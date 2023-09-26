/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** GameSFML.hpp
*/

#pragma once
#include <map>
#include <sstream>
#include "Entity.hpp"
#include "RessourceManager.hpp"
#include "Parser.hpp"
#include "JsonParser2.hpp"
#include "../src/GameEngine/Core.hpp"

class GameSFML
{
public:
    GameSFML();
    ~GameSFML();
    void run();
    void animate();
    void draw();
    void handleEvent();
    void update();
    void getinfos(){};

public:
    sf::RenderWindow _window;
    sf::View _view;
    sf::Event _event;
    sf::Clock _clock;
    RessourceManager _ressourceManager;
    Parser _parser;
    int _event_indicator;
    std::string _eventKey;
    std::unique_ptr<Core> _core;
};
