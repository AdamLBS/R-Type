/*
** EPITECH PROJECT, 2023
** Engine.cpp
** File description:
** Engine
*/

#include "Engine.hpp"

Engine::Engine()
{
    instance = this;
    _isRunning = true;
}

Engine::~Engine()
{
    instance = nullptr;
    _isRunning = false;
}

void Engine::update(std::string event)
{
    for (auto &collider : colliders)
        collider.type1->collideAll(collider.type2, collider.squaredRadius, collider.func);
    for (auto &entity : entities)
        entity->updateAll();
}

void Engine::addEntityType(EntityType<IEntity> *type)
{
    entities.push_back(type);
}

void Engine::removeEntityType(EntityType<IEntity> *type)
{
    entities.remove(type);
}