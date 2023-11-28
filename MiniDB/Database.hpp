#ifndef DB_H
#define DB_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

class DB {
public: 
    void create_table(const std::string& table_name, const std::vector<std::string>& cols);
    void insert_record(const std::string& table_name, std::map<std::string, std::string>& record);
    void load_from_csv(const std::string& table_name);
    void save_to_csv(const std::string& table_name);
    void read(const std::string& table_name);
    void update_record(const std::string& table_name, const std::map<std::string, std::string>& condition, const std::map<std::string, std::string>& new_data);
    void delete_record(const std::string& table_name, const std::map<std::string, std::string>& condition);

private:
    struct Table {
        int id_counter = 0;
        std::vector<std::string> cols;
        std::vector<std::map<std::string, std::string>> records;
    };
    std::map<std::string, Table> tables;
};

#include "Database_Impl.hpp"
#endif