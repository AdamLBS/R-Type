/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** Game
*/

#pragma once
#include "Engine.hpp"
#include "IEntity.hpp"
#include "r-type/Player.hpp"
#include "r-type/Projectile.hpp"
#include <iostream>

class Game
{
public:
    Game(std::shared_ptr<Engine> &engine);
    ~Game();

    void update();

private:
    std::shared_ptr<Engine> _engine;
    std::shared_ptr<EntityType<IEntity>> _playersGroups;
    std::shared_ptr<EntityType<IEntity>> _projectilesGroups;
    std::vector<std::shared_ptr<Player>> _players;
    std::vector<std::shared_ptr<Projectile>> _projectiles;
};
