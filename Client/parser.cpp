/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** parcer.cpp
*/

#include "Parser.hpp"

Parser::Parser()
{
}

Parser::~Parser()
{
}

bool Parser::findEntity(int id)
{
    std::map<int, Entity>::iterator it = _entities.begin();
    while (it != _entities.end())
    {
        if (it->first == id)
            return true;
        it++;
    }
    return false;
}

Entity Parser::loadTexture(Entity entity, std::string path, RessourceManager &ressourceManager)
{
    std::map<std::string, std::shared_ptr<sf::Texture>> textures = ressourceManager.getTextures();
    std::map<std::string, std::shared_ptr<sf::Texture>>::iterator it = textures.begin();
    while (it != textures.end())
    {
        if (it->first == path)
        {
            entity._texture = it->second;
            entity._sprite.setTexture(*entity._texture);
            return entity;
        }
        it++;
    }
    return entity;
}

void Parser::addEntity(std::map<std::string, std::string> value, RessourceManager &ressourceManager)
{
    int id = std::stoi(value["id"]);
    if (findEntity(id) == false)
    {
        Entity entity;
        entity = loadTexture(entity, value["path"], ressourceManager);
        entity.setSpriteScale(sf::Vector2f(std::stof(value["scale.x"]), std::stof(value["scale.y"])));
        entity.setSpriteOrigin();
        entity.setSpriteRotation(std::stof(value["rotation"]));
        entity.setSpritePosition(sf::Vector2f(std::stof(value["x"]), std::stof(value["y"])));
        entity.setRect(std::stoi(value["nbRect"]));
        _entities[id] = entity;
    }
}

void Parser::removeEntity(std::map<std::string, std::string> value)
{
    int id = std::stoi(value["id"]);
    if (findEntity(id) == true)
    {
        _entities.erase(id);
    }
}

void Parser::modifyPosEntity(std::map<std::string, std::string> value)
{
    int id = std::stoi(value["id"]);
    if (findEntity(id) == true)
    {
        _entities[id].setSpritePosition(sf::Vector2f(std::stof(value["x"]), std::stof(value["y"])));
    }
}

std::string Parser::setKey(std::string key, int i)
{
    if (i == 0)
        key = "id";
    else if (i == 1)
        key = "x";
    else if (i == 2)
        key = "y";
    else if (i == 3)
        key = "path";
    else if (i == 4)
        key = "rotation";
    else if (i == 5)
        key = "scale.x";
    else if (i == 6)
        key = "scale.y";
    else if (i == 7)
        key = "nbRect";
    return key;
}

void Parser::parseMessage(std::string message, RessourceManager &ressourceManager)
{
    std::size_t com = message.find(' ');
    if (com != std::string::npos)
    {
        std::string commande = message.substr(0, com);
        std::string tmp = message.substr(com);
        if (commande == "ecreate")
        {
            std::istringstream iss(tmp);
            std::map<std::string, std::string> valueMap;
            std::string key;
            std::string token;
            for (int i = 0; iss >> token; i++)
            {
                key = setKey(key, i);
                valueMap[key] = token;
                key.clear();
            }
            addEntity(valueMap, ressourceManager);
        }
        else if (commande == "pmove" || commande == "emove")
        {
            std::istringstream iss(tmp);
            std::map<std::string, std::string> valueMap;
            std::string key;
            std::string token;
            for (int i = 0; iss >> token; i++)
            {
                key = setKey(key, i);
                valueMap[key] = token;
                key.clear();
            }
            modifyPosEntity(valueMap);
        }
        else if (commande == "dead" || commande == "edead")
        {
            std::istringstream iss(tmp);
            std::map<std::string, std::string> valueMap;
            std::string key;
            std::string token;
            for (int i = 0; iss >> token; i++)
            {
                key = setKey(key, i);
                valueMap[key] = token;
                key.clear();
            }
            removeEntity(valueMap);
        }
    }
}