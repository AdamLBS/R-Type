/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** Tank
*/

#pragma once

#include "../Character.hpp"
#include <chrono>

class Tank : public Character
{
public:
    Tank(std::string path, float x, float y, int id, int nbSprite = 1, float angle = 0, float scaleX = 1, float scaleY = 1);
    ~Tank();

protected:
private:
};