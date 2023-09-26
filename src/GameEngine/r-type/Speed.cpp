/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** Speed
*/

#include "Speed.hpp"

Speed::Speed(std::string path, float x, float y, int id, float angle, float scaleX, float scaleY, int life, float speed, int damage, int fireRate, int nbSprite)
    : Player(path, x, y, id, angle, scaleX, scaleY, life, speed, damage, fireRate, nbSprite)
{
}

Speed::~Speed()
{
}