#pragma once
#include <string>
#include "Database.h"
#include "sqlite3.h"
class ListItem
{
	Database m_database;
public:
	void add(const std::string& name, const std::string& desc, const std::string& date, const std::string& cat);
	void update(const std::string& name, const std::string& desc, const std::string& date, const std::string& cat, const std::string& old_name);
	void done(const std::string& name);
	void del(const std::string& name);
	void select(std::string& inputQuery);
};

