#include "sqlite3.h"
#include "ListItem.h"
#include "CommandParser.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

int main(int argc, char** argv) {
    ListItem lItem;
    CommandParser parser;
    int choice;
    while (1) {
        std::cout << "Enter command: ";
        std::string command;
        std::getline(std::cin, command);
        std::vector<std::string> fields = parser.split(command);

        if (fields[0] == "add") {
            if (fields.size() != 6) {
                std::cout << "Unknown command\n";
                break;
            }
            lItem.add(fields[1], fields[2], fields[3] + " " + fields[4], fields[5]);
        }
        else if (fields[0] == "done") {
            if (fields.size() != 2) {
                std::cout << "Unknown command\n";
                break;
            }
            lItem.done(fields[1]);
        }
        else if (fields[0] == "update") {
            if (fields.size() != 2) {
                std::cout << "Unknown command\n";
                break;
            }
            std::string new_name, new_desc, new_cat, new_date;
            std::cout << "Enter name: ";
            std::cin >> new_name;
            std::cout << "Enter description: ";
            std::cin >> new_desc;
            std::cout << "Enter date: ";
            std::cin >> new_date;
            std::cout << "Enter category: ";
            std::cin >> new_cat;
            lItem.update(new_name, new_desc, new_date, new_cat, fields[1]);
        }
        else if (fields[0] == "delete") {
            if (fields.size() != 2) {
                std::cout << "Unknown command\n";
                break;
            }
            lItem.del(fields[1]);
        }
        else if (fields[0] == "select") {
            lItem.select(command);
        }
        else if (fields[0] == "cls") {
            if (fields.size() != 1) {
                std::cout << "Unknown command\n";
                break;
            }
            system("cls");
        }
        else if (fields[0] == "exit") {
            if (fields.size() != 1) {
                std::cout << "Unknown command\n";
                break;
            }
            break;
        }
        else {
            std::cout << "Unknown command\n";
            break;
        }
    }
    return EXIT_SUCCESS;
}
