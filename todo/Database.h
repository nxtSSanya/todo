#pragma once
#include "sqlite3.h"
#include <iostream>
#include <string>

class Database
{
public:
	Database() {
        if (sqlite3_open("test.db", &m_db) == SQLITE_OK) {

            std::string query = "CREATE TABLE IF NOT EXISTS " + m_dbName + " (name varchar(50), description varchar(100), date datetime, category varchar(50), status varchar(5));";
            int result = sqlite3_prepare_v2(m_db, query.c_str(), -1, &m_stmt, NULL);
            sqlite3_step(m_stmt);
            sqlite3_finalize(m_stmt);

            if (result != SQLITE_OK) {
                std::cout << sqlite3_errmsg(m_db) << std::endl;
            }
        }
	}
    ~Database() {
        sqlite3_close(m_db);
    }
	sqlite3* m_db;
    sqlite3_stmt* m_stmt;
	std::string m_dbName = "ListItem";
	std::string getDatabaseName() const;
    void setDatabaseName(const std::string& dbName);
	void pushQuery(const std::string& s);
    void selectQuery(const std::string& query);
};

