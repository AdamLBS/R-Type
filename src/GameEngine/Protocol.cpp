/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** Protocol
*/

#include "Protocol.hpp"

Protocol::Protocol()
{
}

Protocol::~Protocol()
{
}

std::vector<std::string> Protocol::transformEntityInitToProtocol(std::list<EntityType<IEntity> *> entities)
{
    std::vector<std::string> protocol;
    for (auto entityType : entities)
    {
        for (auto entity : entityType->getEntities())
        {
            auto pos = entity->getPosition();
            auto scale = entity->getScale();
            protocol.push_back("ecreate " + std::to_string(entity->getId()) + " " + entity->getPath() + " " + std::to_string(std::get<0>(pos)) + " " + std::to_string(std::get<1>(pos)) + " " + std::to_string(entity->getRotation()) + " " + std::to_string(std::get<0>(scale)) + " " + std::to_string(std::get<1>(scale)));
        }
    }
    return protocol;
}

std::vector<std::string> Protocol::transformEntityChangeToProtocol(std::list<EntityType<IEntity> *> entities)
{
    std::vector<std::string> protocol;
    for (auto entityType : entities)
    {
        for (auto entity : entityType->getEntities())
        {
            const auto pos = entity->getPosition();
            const auto oldPos = entity->getOldPosition();
            if (std::get<0>(pos) != std::get<0>(oldPos) || std::get<1>(pos) != std::get<1>(oldPos))
                protocol.push_back("emove " + std::to_string(entity->getId()) + " " + std::to_string(std::get<0>(pos)) + " " + std::to_string(std::get<1>(pos)));
        }
    }
    return protocol;
}