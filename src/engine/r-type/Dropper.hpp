/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** Dropper
*/

#pragma once

#include "../Character.hpp"

class Dropper : public Character {
   public:
    Dropper(EntityInfo info);
    ~Dropper();
    void update() override;
    void move(float x, float y) override;

   protected:
   private:
};
