#include "Database.hpp"

void DB::create_table(const std::string &table_name, const std::vector<std::string> &cols)
{
    if (tables.find(table_name) == tables.end()) {
        tables[table_name] = {{}, cols, {}};
        std::cout << "Table " << table_name << " created with cols: ";
        for (auto& col : cols) {
            std::cout << col << " "; 
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Create with other name" << std::endl;
    }
}

inline void DB::insert_record(const std::string &table_name, std::map<std::string, std::string>& record)
{
    if (tables.find(table_name) != tables.end()) {
        int next_id = ++tables[table_name].id_counter;
        record["id"] = std::to_string(next_id);

        tables[table_name].records.push_back(record);
        std::cout << "Insertion completed succesfully" << std::endl;
        save_to_csv(table_name);
    }
}

inline void DB::load_from_csv(const std::string &table_name)
{
    std::ifstream file(table_name + ".csv");
    if (!file.is_open()) {
        std::cerr << "ERROR WHILE OPENING" << std::endl;
        return;
    }

    tables[table_name].records.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::map<std::string, std::string> record;
        std::istringstream iss(line);
        std::string value;

        for (auto& col : tables[table_name].cols) {
            std::getline(iss, value, ',');
            record[col] = value;
        }

        tables[table_name].records.push_back(record);
    }

    file.close();
    std::cout << "Succesfully loaded" << std::endl;
}

inline void DB::save_to_csv(const std::string &table_name)
{
    std::ofstream file(table_name + ".csv");
    if (!file.is_open()) {
        std::cerr << "ERROR WHILE OPENING" << std::endl;
        return;        
    }

    for (auto& record : tables[table_name].records) {
        for (auto& col : tables[table_name].cols) {
            file << record[col] << ",";
        }
        file << std::endl;
    }

    file.close();
    std::cout << "Succesfully saved" << std::endl;
}

inline void DB::read(const std::string &table_name)
{
    if (tables.find(table_name) != tables.end()) {
        std::cout << "Recs from table " << table_name << std::endl;
        for (auto& col : tables[table_name].cols) {
            std::cout << col << '\t';
        }
        std::cout << std::endl;

        for (auto& rec : tables[table_name].records) {
            for (auto& col : tables[table_name].cols) {
                std::cout << rec.at(col) << '\t';
            }
            std::cout << std::endl;
        }
    }
    else {
        std::cout << "Such table doesn't exist" << std::endl;
    }
}

inline void DB::update_record(const std::string &table_name, const std::map<std::string, std::string> &condition, const std::map<std::string, std::string> &new_data)
{
    if (tables.find(table_name) != tables.end()) {
        for (auto& rec : tables[table_name].records) {
            bool match = true;
            for (auto& cond : condition) {
                if (rec[cond.first] != cond.second) {
                    match = false;
                    break;
                }
            }
            if (match) {
                for (auto& entry : new_data) {
                    rec[entry.first] = entry.second;
                }
                std::cout << "Succesfully updated" << std::endl;
                save_to_csv(table_name);
                return;
            }
        }
        std::cout << "Such record doesn't exist" << std::endl;
    }
    else {
        std::cout << "Such table doesn't exist" << std::endl;
    }
}

inline void DB::delete_record(const std::string &table_name, const std::map<std::string, std::string> &condition)
{
    if (tables.find(table_name) != tables.end()) {
        auto& records = tables[table_name].records;
        auto it = std::remove_if(records.begin(), records.end(), [&](auto& record) {
            for (auto& cond : condition) {
                if (record[cond.first] != cond.second) {
                    return false;
                }
            }
            return true;
        });
        records.erase(it, records.end());
        std::cout << "Succesfully deleted" << std::endl;
        save_to_csv(table_name); 
    }
    else {
         std::cout << "Such table doesn't exist" << std::endl;
    }
}