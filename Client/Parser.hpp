/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** Parser.hpp
*/

#pragma once
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <sstream>
#include "Entity.hpp"
#include "RessourceManager.hpp"
#include "JsonParser2.hpp"

class Parser
{
    public:
        Parser();
        ~Parser();
        bool findEntity(int id);
        Entity loadTexture(Entity entity, std::string path, RessourceManager &ressourceManager);
        void addEntity(std::map<std::string, std::string> value, RessourceManager &ressourceManager);
        void removeEntity(std::map<std::string, std::string> value);
        void updateEntity(std::map<std::string, std::string> value);
        void modifyPosEntity(std::map<std::string, std::string> value);
        void getConfig(std::string path, std::string type, Entity *entity);
        std::string setKey(std::string key, int i);
        void parseMessage(std::string message, RessourceManager &ressourceManager);
    public:
        std::map<int, Entity> _entities;
};