# Mini-Database-Application

This project implements a simple Database Management System (DBMS) in C++. The DBMS allows users to create tables, insert records, load and save data from/to CSV files, read records, update records based on conditions, and delete records based on conditions.

## Overview

The project consists of a `DB` class that provides basic database functionalities. It manages tables, records, and supports operations commonly found in relational databases. The data is stored in CSV files for simplicity.

## Usage

The main functionalities of the database are accessible through the DB class. The available methods include:

create_table: Create a new table with specified columns.
insert_record: Insert a new record into a table.
load_from_csv: Load records from a CSV file into a table.
save_to_csv: Save records from a table to a CSV file.
read: Display records from a table.
update_record: Update records in a table based on specified conditions.
delete_record: Delete records from a table based on specified conditions.
