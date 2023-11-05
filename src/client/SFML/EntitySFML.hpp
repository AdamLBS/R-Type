/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** Sprite.hpp
*/

#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include <string>
#include "../IEntity.hpp"
#include "RessourceManagerSFML.hpp"

class EntitySFML : public IEntity {
   public:
    EntitySFML(std::shared_ptr<RessourceManagerSFML> ressourceManager);
    ~EntitySFML();
    void setTexture(const std::string& path);
    void setSpriteScale(float scaleX, float scaleY);
    void setPosition(float x, float y);
    std::tuple<float, float> getSpritePosition() const;
    void setSpriteOriginToCenter();
    void setRect(int nb, int initRect = 0);
    void animateSprite(const int ei, const float framerate);
    void setInitPos();
    void setTextString(std::string str);
    void setType(IEntity::Type type);
    void setTextInfo(int size, std::string color);
    void setSpeed(float speed);
    void setNextPos(float x, float y);
    void setDirection(std::string direction);
    void update();
    void flip();
    void setHit(bool touch);
    bool isDead() const;
    void setEventForm(std::string form);
    void setObjectType(std::string type);
    void setSpriteColor(sf::Color color);
    sf::Color getColor(std::string color);
    IEntity::Type getType() const;
    void makePrediction();
    std::string getEventForm() const;
    void setFont();
    void draw(sf::RenderWindow& window);
    sf::Sprite getSprite() const;
    void setSound(const std::string& path);

   public:
    sf::Sprite _sprite;
    sf::Sound _sound;
    std::shared_ptr<sf::Texture> _texture;
    int _nbRect;
    int _initRect;
    std::string _direction;
    sf::Clock _clock;
    std::string _eventForm;
    std::string _objectType;
    int _oldPosY;
    IEntity::Type _type;
    sf::Text _text;
    sf::Font _font;
    float _speed;
    sf::Vector2f _nextPos;
    bool _isHit = false;
    std::shared_ptr<RessourceManagerSFML> _ressourceManager;
};

// ecreate id x y text size color