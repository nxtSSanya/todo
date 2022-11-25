#pragma once
#include <vector>
#include <iterator>
#include <string>
#include <sstream>

class CommandParser
{
public:
    std::vector<std::string> split(std::string const& input);
};

