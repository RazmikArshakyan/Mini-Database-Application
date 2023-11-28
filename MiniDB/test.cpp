#include <map>
#include <vector>
#include "Database.hpp"

int main() {
    // Create an instance of the Database class
    DB myDatabase;

    // Create a table with columns
    myDatabase.create_table("students", {"name", "age", "grade"});

    // Insert records into the table
    std::map<std::string, std::string> record1 = {{"name", "John"}, {"age", "25"}, {"grade", "A"}};
    std::map<std::string, std::string> record2 = {{"name", "Alice"}, {"age", "22"}, {"grade", "B"}};
    std::map<std::string, std::string> record3 = {{"name", "Walter"}, {"age", "45"}, {"grade", "A+"}};
    std::map<std::string, std::string> record4 = {{"name", "Jesse"}, {"age", "22"}, {"grade", "F"}};

    myDatabase.insert_record("students", record1);
    myDatabase.insert_record("students", record2);
    myDatabase.insert_record("students", record3);
    myDatabase.insert_record("students", record4);
    
    // Read and display the records
    myDatabase.read("students");

    // Update a record
    std::map<std::string, std::string> condition = {{"name", "John"}};
    std::map<std::string, std::string> new_data = {{"grade", "B"}};
    myDatabase.update_record("students", condition, new_data);

    // Read and display the records after the update
    myDatabase.read("students");

    // Delete a record
    std::map<std::string, std::string> delete_condition = {{"name", "Alice"}};
    myDatabase.delete_record("students", delete_condition);

    // Read and display the records after the delete
    myDatabase.read("students");

    // Load records from CSV file
    myDatabase.load_from_csv("students");

    // Read and display the records after loading from CSV
    myDatabase.read("students");

    return 0;
}