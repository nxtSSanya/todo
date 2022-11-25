cmake_minimum_required(VERSION 3.13)

project(todoList VERSION 1.0 LANGUAGES CXX)

if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

add_executable(todoList main.cpp sqlite3.c shell.c sqlite3.h sqlite3ext.h Database.cpp Database.h ListItem.cpp ListItem.h CommandParser.cpp CommandParser.h ) 
