/*
** EPITECH PROJECT, 2023
** InstanceButton.cpp
** File description:
** InstanceButton
*/
#ifndef B_CPP_500_MAR_5_1_RTYPE_MARTIN_RAMDANE_INSTANCEBUTTON_H
#define B_CPP_500_MAR_5_1_RTYPE_MARTIN_RAMDANE_INSTANCEBUTTON_H

#include <map>
#include <memory>
#include "../types/Instance.hpp"
#include "SFML/EntitySFML.hpp"
#include "SFML/RessourceManagerSFML.hpp"

class InstanceButton {
   public:
    InstanceButton(InstanceType instance, int x, int y);

    ~InstanceButton();

    std::string formatText(std::string toFormat);

    int getId() { return _instance.id; }

    int getPort() { return _instance.port; }

    std::map<std::string, std::shared_ptr<EntitySFML>> getEntities() {
        return _entities;
    }

    EntitySFML* getSubmitButton();

    void setPosition(int x, int y);

    std::map<std::string, std::shared_ptr<sf::Text>> getTexts() {
        return _texts;
    }

    bool hasSubmitButton() {
        return _instance.nbPlayers < _instance.maxPlayers;
    }

   private:
    sf::Font _font;
    InstanceType _instance;
    int _x;
    int _y;
    std::map<std::string, std::shared_ptr<EntitySFML>> _entities;
    std::map<std::string, std::shared_ptr<sf::Text>> _texts;
};

#endif  //B_CPP_500_MAR_5_1_RTYPE_MARTIN_RAMDANE_INSTANCEBUTTON_H
