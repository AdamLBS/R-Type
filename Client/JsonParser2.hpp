/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** JsonParser2.hpp
*/

#pragma once

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>
#include <string>
#include <algorithm>

class JsonParser2
{
public:
    JsonParser2();
    ~JsonParser2();
    nlohmann::json readFile(std::string const &path);
    std::vector<std::string> split(std::string const &str, char const delim) noexcept;

    template <typename T>
    T get(nlohmann::json const jsonData, std::string const key)
    {
        int cou = count(key.begin(), key.end(), '.');
        std::vector<std::string> keys = split(key, '.');

        nlohmann::json const *leaf = &jsonData;

        if (cou > 0)
        {
            for (int i = 0; i <= cou; i++)
            {
                if (leaf->contains(keys[i]))
                {
                    leaf = &leaf->at(keys[i]);
                }
                else
                {
                    // std::cerr << "Key '" << keys[i] << "' not found!" << std::endl;
                    return T();
                }
            }
        }
        return leaf->get<T>();
    }
};