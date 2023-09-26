/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** GameSFML.cpp
*/

#include "GameSFML.hpp"

GameSFML::GameSFML()
{
    _window.create(sf::VideoMode(1920, 1080), "R-TYPE");
    _window.setFramerateLimit(60);
    _view = sf::View(sf::FloatRect(0, 0, 850, 478));
    _ressourceManager = RessourceManager();
    _parser = Parser();
    _core = std::make_unique<Core>();
}

GameSFML::~GameSFML()
{
}

void GameSFML::run()
{
    while (_window.isOpen())
    {
        // getinfos -> appel de parseMessage
        std::vector<std::string> protocol = _core->mainLoop(_eventKey);
        for (auto line : protocol)
            _parser.parseMessage(line, _ressourceManager);

        handleEvent();
        update();
    }
}

void GameSFML::handleEvent()
{
    _eventKey = "";
    while (_window.pollEvent(_event))
    {
        if (_event.type == sf::Event::Closed)
            _window.close();
        if (_event.type == sf::Event::KeyPressed)
        {
            switch (_event.key.code)
            {
            case sf::Keyboard::Left:
                // send left;
                _eventKey = "LEFT";
                break;
            case sf::Keyboard::Right:
                // send right
                _eventKey = "RIGHT";
                break;
            case sf::Keyboard::Up:
                // send up
                _eventKey = "UP";
                break;
            case sf::Keyboard::Down:
                // send down
                _eventKey = "DOWN";
                break;
            case sf::Keyboard::Space:
                // send shoot
                _eventKey = "SHOOT";
                break;
            default:
                _eventKey = "";
                break;
            }
        }
    }
}

void GameSFML::update()
{
    _window.clear();
    std::map<int, Entity>::iterator it = _parser._entities.begin();
    while (it != _parser._entities.end())
    {
        if ((it->second).getRect() > 1)
            it->second.animateSprite();
        _window.draw(it->second.getSprite());
        it++;
    }
    _window.setView(_view);
    _window.display();
}
