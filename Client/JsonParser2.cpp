/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** JsonParser2.cpp
*/

#include "JsonParser2.hpp"

JsonParser2::JsonParser2()
{
}

JsonParser2::~JsonParser2()
{
}

nlohmann::json JsonParser2::readFile(std::string const &path)
{
    std::ifstream inputFile(path);
    return nlohmann::json::parse(inputFile);
}

std::vector<std::string> JsonParser2::split(std::string const &str, char const delim) noexcept
{
    std::vector<std::string> res = {};
    std::size_t start{0};
    std::size_t end{0};
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        res.push_back(str.substr(start, end - start));
    }
    return res;
}
