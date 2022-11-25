#include "ListItem.h"
#include "sqlite3.h"
#include <algorithm>
#include <string>
#include <functional>


void ListItem::add(const std::string& name, const std::string& desc, const std::string& date, const std::string& cat)
{
	std::string query = "INSERT INTO " + 
		m_database.getDatabaseName() + 
		" (name, description, date, category, status) VALUES ('" + name + "', '" + desc + "', '" + date + "', '" + cat + "', '" + "on');";
	m_database.pushQuery(query);
}

void ListItem::update(const std::string& name, const std::string& desc, const std::string& date, const std::string& cat, const std::string& old_name)
{
	std::string query = "UPDATE " + m_database.getDatabaseName() +
		" SET name = '" + name + "', description = '" + desc + "', date = '" + date + "', category = '" + cat + "' WHERE name = '" + old_name +"'";
	m_database.pushQuery(query);
}

void ListItem::done(const std::string& name)
{
	std::string query = "UPDATE " + m_database.getDatabaseName() + " SET status = 'off' WHERE name = '" + name + "'";
	m_database.pushQuery(query);
}

void ListItem::del(const std::string& name)
{
	std::string query = "DELETE FROM " + m_database.getDatabaseName() + " WHERE name = '" + name + "'";
	m_database.pushQuery(query);
}

void ListItem::select(std::string& inputQuery)
{
	std::string needle = "where";
	if (const auto it = std::search(inputQuery.begin(), inputQuery.end(), needle.begin(), needle.end()); it != inputQuery.end()) {
		inputQuery.insert(it - inputQuery.begin(), " FROM " + m_database.getDatabaseName() + " ");
	}
	else {
		inputQuery.insert(it - inputQuery.begin(), " FROM " + m_database.getDatabaseName() + " ");
	}
	m_database.selectQuery(inputQuery);
}
