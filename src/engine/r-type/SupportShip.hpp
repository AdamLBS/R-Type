/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** SupportShip
*/

#pragma once

#include <chrono>
#include "../Character.hpp"

class SupportShip : public Character {
   public:
    SupportShip(EntityInfo info, int relatedPlayerId);
    SupportShip(EntityInfo info);
    ~SupportShip();
    void shoot() override;
    void update() override;
    int getRelatedPlayerId() const;
    void launch();

   protected:
   private:
    int _relatedPlayerId;
    bool _launched = false;
    int _launchX = 0;
    int _playerOldX = 0;
    int _playerOldY = 0;
};
