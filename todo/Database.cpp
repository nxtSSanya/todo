#include "Database.h"
#include "sqlite3.h"

std::string Database::getDatabaseName() const
{
    return m_dbName;
}

void Database::pushQuery(const std::string& query)
{
    int res = sqlite3_prepare_v2(m_db, query.c_str(), -1, &m_stmt, NULL);
    sqlite3_step(m_stmt);
    sqlite3_finalize(m_stmt);
    if (res != SQLITE_OK) {
        std::cout << sqlite3_errmsg(m_db) << std::endl;
    }
}

void Database::setDatabaseName(const std::string& dbName)
{
    m_dbName = dbName;
}

void Database::selectQuery(const std::string& query) {
    int res = sqlite3_prepare_v2(m_db, query.c_str(), -1, &m_stmt, NULL);
    if (res != SQLITE_OK) {
        std::cout << sqlite3_errmsg(m_db) << std::endl;
    }
    else {
        std::cout << "________________________________________________\n";
        while (res = sqlite3_step(m_stmt) == SQLITE_ROW) {
            std::cout << "Name:\t\t" << sqlite3_column_text(m_stmt, 0)      << "\n";
            std::cout << "Description:\t" << sqlite3_column_text(m_stmt, 1) << "\n";
            std::cout << "Date:\t\t" << sqlite3_column_text(m_stmt, 2)      << "\n";
            std::cout << "Category:\t" << sqlite3_column_text(m_stmt, 3)    << "\n";
            std::cout << "Status:\t\t" << sqlite3_column_text(m_stmt, 4)    << "\n";
            std::cout << "________________________________________________\n";
        }  
    }
}
