/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** Sprite.hpp
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <memory>
#include <iostream>
#include <string>

class Entity
{
public:
    Entity(){};
    ~Entity(){};
    void setTexture(const std::string &path);
    void setSprite();
    void setSpriteScale(const sf::Vector2f &scale);
    void setSpritePosition(const sf::Vector2f &pos);
    void setSpriteOrigin();
    void setSpriteRotation(const float &rotation);
    void setRect(int nb);
    void animateSprite();
    sf::Sprite getSprite() const;
    sf::Texture getTexture() const;
    sf::Vector2f getSpritePosition() const;
    int getRect() const { return _nbRect; };

public:
    sf::Sprite _sprite;
    std::shared_ptr<sf::Texture> _texture;
    int _nbRect;
    sf::Clock clock;
};