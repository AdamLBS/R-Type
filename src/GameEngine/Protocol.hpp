/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** Protocol
*/

#pragma once
#include <vector>
#include <string>
#include <list>
#include "IEntity.hpp"
#include "EntityType.hpp"
#include <iostream>
#include "r-type/Game.hpp"

class Protocol
{
public:
    Protocol();
    ~Protocol();

    static std::string transformEntityCreateToProtocol(std::shared_ptr<IEntity> entity);
    static std::string transformEntityMoveToProtocol(std::shared_ptr<IEntity> entity);
    static std::vector<std::string> transformEntitiesToProtocol(std::list<EntityType<IEntity> *> entities);
    static Game::Event transformProtocolToEvent(std::string event);

protected:
private:
};