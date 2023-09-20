/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** Projectile
*/

#pragma once

#include "../IEntity.hpp"

class Projectile : public IEntity
{
public:
    Projectile(std::string path, float x, float y, float angle = 0, float scaleX = 1, float scaleY = 1, float speed = 1);
    ~Projectile();
    void setPosition(float x, float y);
    void setRotation(float angle);
    void move(float x, float y);
    void rotate(float angle);
    void update(std::string event);
    std::tuple<float, float> getPosition() const;
    float getRotation() const;
    void setScale(float x, float y);
    std::tuple<float, float> getScale() const;
    std::string getPath() const;
    void setPath(std::string path);
    float getSpeed() const;
    void setSpeed(float speed);

protected:
private:
    std::string _path;
    float _x;
    float _y;
    float _angle;
    float _scaleX;
    float _scaleY;
    float _speed;
};