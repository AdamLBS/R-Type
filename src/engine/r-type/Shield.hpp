/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** Shield
*/

#pragma once

#include <chrono>
#include <memory>
#include "../Character.hpp"

class Shield : public Character {
   public:
    Shield(EntityInfo info);
    ~Shield();

    void activateShield();
    void deactivateShield();
    bool isShieldUp() const;
    bool canActivateShield() const;
    void update() override;
    void action() override;
    void takeDamage(int damage) override;

   protected:
   private:
    bool _shieldIsUp = false;
    bool _canActivateShield = true;

    std::chrono::duration<double> _targetShieldDuration;
    std::chrono::duration<double> _reloadShieldDuration;
    std::chrono::high_resolution_clock::time_point _shieldStart;
    std::chrono::high_resolution_clock::time_point _shieldEnd;
    std::shared_ptr<AEntity> _shield;
};
