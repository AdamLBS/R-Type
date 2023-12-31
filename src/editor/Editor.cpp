/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** startGame.cpp
*/

#include "Editor.hpp"

Editor::Editor() {
    _window = std::make_shared<sf::RenderWindow>();
    _window->create(sf::VideoMode(1920, 1080), "R-Type-Editor");
    _mainView = sf::View(sf::FloatRect(0, 0, 850, 478));
    _menuView = sf::View(sf::FloatRect(0, 0, 850, 478));
    _window->setFramerateLimit(60);
    if (!_font.loadFromFile(std::string("font/pixel.ttf")))
        std::cerr << "Error: could not load font" << std::endl;

    _ressourceManager = std::make_shared<RessourceManagerSFML>();

    _entities["background"] = std::make_unique<EntitySFML>(_ressourceManager);
    _entities["background"]->setTexture("background.png");
    _entities["background"]->setPosition(0, 0);

    //menu entities
    _entitiesSelectMenu["flyer"] =
        std::make_unique<EntitySFML>(_ressourceManager);
    _entitiesSelectMenu["flyer"]->setTexture("flyer.png");
    _entitiesJsonConfig["flyer"] = "Flyer.rType.json";

    _entitiesSelectMenu["OrangeRobot"] =
        std::make_unique<EntitySFML>(_ressourceManager);
    _entitiesSelectMenu["OrangeRobot"]->setTexture("OrangeRobot.png");
    _entitiesJsonConfig["OrangeRobot"] = "OrangeRobot.rType.json";

    _entitiesSelectMenu["bomberman"] =
        std::make_unique<EntitySFML>(_ressourceManager);
    _entitiesSelectMenu["bomberman"]->setTexture("bomberman.png");
    _entitiesJsonConfig["bomberman"] = "Bomberman.rType.json";

    _entitiesSelectMenu["GreenRobot"] =
        std::make_unique<EntitySFML>(_ressourceManager);
    _entitiesSelectMenu["GreenRobot"]->setTexture("GreenRobot.png");
    _entitiesJsonConfig["GreenRobot"] = "GreenRobot.rType.json";

    _entitiesSelectMenu["worm"] =
        std::make_unique<EntitySFML>(_ressourceManager);
    _entitiesSelectMenu["worm"]->setTexture("worm.png");
    _entitiesJsonConfig["worm"] = "Worm.rType.json";

    _entitiesSelectMenu["dropper"] =
        std::make_unique<EntitySFML>(_ressourceManager);
    _entitiesSelectMenu["dropper"]->setTexture("dropper.png");
    _entitiesJsonConfig["dropper"] = "Dropper.rType.json";

    _entitiesSelectMenu["CircularRobot"] =
        std::make_unique<EntitySFML>(_ressourceManager);
    _entitiesSelectMenu["CircularRobot"]->setTexture("CircularRobot.png");
    _entitiesJsonConfig["CircularRobot"] = "CircularRobot.rType.json";

    _entitiesSelectMenu["boss1"] =
        std::make_unique<EntitySFML>(_ressourceManager);
    _entitiesSelectMenu["boss1"]->setTexture("boss1.png");
    _entitiesJsonConfig["boss1"] = "Boss1.rType.json";

    _entitiesSelectMenu["boss2"] =
        std::make_unique<EntitySFML>(_ressourceManager);
    _entitiesSelectMenu["boss2"]->setTexture("boss2.png");
    _entitiesJsonConfig["boss2"] = "Boss2.rType.json";

    _entitiesSelectMenu["wall1"] =
        std::make_unique<EntitySFML>(_ressourceManager);
    _entitiesSelectMenu["wall1"]->setTexture("wall1.png");
    _entitiesJsonConfig["wall1"] = "Wall1.rType.json";

    _entitiesSelectMenu["wall2"] =
        std::make_unique<EntitySFML>(_ressourceManager);
    _entitiesSelectMenu["wall2"]->setTexture("wall2.png");
    _entitiesJsonConfig["wall2"] = "Wall2.rType.json";

    _entitiesSelectMenu["wall3"] =
        std::make_unique<EntitySFML>(_ressourceManager);
    _entitiesSelectMenu["wall3"]->setTexture("wall3.png");
    _entitiesJsonConfig["wall3"] = "Wall3.rType.json";

    for (auto& entity : _entitiesSelectMenu) {
        //opacity
        entity.second->setSpriteColor(sf::Color(255, 255, 255, 100));
    }

    _saveButton = std::make_unique<EntitySFML>(_ressourceManager);
    _saveButton->setTexture("save.png");
    _saveButton->setPosition(800, 430);
    _saveButton->setSpriteScale(0.1, 0.1);

    _music1 = std::make_unique<EntitySFML>(_ressourceManager);
    _music1->setTexture("music.png");
    _music1->setPosition(400, 10);
    _music1->setSpriteScale(0.1, 0.1);

    _music2 = std::make_unique<EntitySFML>(_ressourceManager);
    _music2->setTexture("music.png");
    _music2->setPosition(500, 10);
    _music2->setSpriteScale(0.1, 0.1);

    _musics["music1"].openFromFile("sounds/r-type/level1.ogg");
    _musics["music1"].setLoop(true);
    _musics["music2"].openFromFile("sounds/r-type/level2.ogg");
    _musics["music2"].setLoop(true);

    //create Rects
    _entitiesRect["flyer"] = std::make_tuple(8, 0);
    _entitiesRect["OrangeRobot"] = std::make_tuple(2, 0);
    _entitiesRect["bomberman"] = std::make_tuple(7, 0);
    _entitiesRect["GreenRobot"] = std::make_tuple(3, 0);
    _entitiesRect["worm"] = std::make_tuple(6, 0);
    _entitiesRect["dropper"] = std::make_tuple(12, 0);
    _entitiesRect["boss1"] = std::make_tuple(7, 0);
    _entitiesRect["CircularRobot"] = std::make_tuple(8, 0);
    _entitiesRect["wall1"] = std::make_tuple(1, 0);
    _entitiesRect["wall2"] = std::make_tuple(1, 0);
    _entitiesRect["wall3"] = std::make_tuple(1, 0);
    _entitiesRect["boss2"] = std::make_tuple(2, 0);

    _entityQuantity["background"] = 0;

    for (auto& entity : _entitiesSelectMenu) {
        entity.second->setRect(std::get<0>(_entitiesRect[entity.first]),
                               std::get<1>(_entitiesRect[entity.first]));
    }

    //texts
    _texts["X"] = std::make_unique<sf::Text>();
    _texts["X"]->setFont(_font);
    _texts["X"]->setString("x: 0");
    _texts["X"]->setCharacterSize(20);
    _texts["X"]->setFillColor(sf::Color::Red);
    _texts["X"]->setPosition(sf::Vector2f(750, 5));
    _texts["X"]->setOrigin(
        sf::Vector2f(_texts["X"]->getLocalBounds().width / 2,
                     _texts["X"]->getLocalBounds().height / 2));

    _texts["Y"] = std::make_unique<sf::Text>();
    _texts["Y"]->setFont(_font);
    _texts["Y"]->setString("y: 0");
    _texts["Y"]->setCharacterSize(20);
    _texts["Y"]->setFillColor(sf::Color::Red);
    _texts["Y"]->setPosition(sf::Vector2f(750, 30));
    _texts["Y"]->setOrigin(
        sf::Vector2f(_texts["Y"]->getLocalBounds().width / 2,
                     _texts["Y"]->getLocalBounds().height / 2));

    _texts["help"] = std::make_unique<sf::Text>();
    _texts["help"]->setFont(_font);
    _texts["help"]->setString("Select entities with the keys 1 to Equal\n");
    _texts["help"]->setCharacterSize(15);
    _texts["help"]->setFillColor(sf::Color::Red);
    _texts["help"]->setPosition(sf::Vector2f(25, 460));
    _texts["help"]->setOrigin(
        sf::Vector2f(_texts["Y"]->getLocalBounds().width / 2,
                     _texts["Y"]->getLocalBounds().height / 2));

    _texts["name"] = std::make_unique<sf::Text>();
    _texts["name"]->setFont(_font);
    _texts["name"]->setString("flyer");
    _texts["name"]->setCharacterSize(20);
    _texts["name"]->setFillColor(sf::Color::White);
    _texts["name"]->setPosition(sf::Vector2f(60, 10));
    _texts["name"]->setOrigin(
        sf::Vector2f(_texts["name"]->getLocalBounds().width / 2,
                     _texts["name"]->getLocalBounds().height / 2));

    _inputs["levelName"] = std::make_unique<Input>(
        "assets/cenario/TextInput.png", "assets/cenario/TextInputHover.png", "",
        _ressourceManager);
    _inputs["levelName"]->setSpritePosition(sf::Vector2f(330, 220));
    _inputs["levelName"]->setSpriteScale(sf::Vector2f(2, 2));
}

Editor::~Editor() {
    _window->close();
}

void Editor::keyEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            _mainView.move(-15, 0);
            _entities["background"]->setPosition(
                _entities["background"]->getSprite().getPosition().x - 15,
                _entities["background"]->getSprite().getPosition().y);
            _x -= 15;
        } else if (event.key.code == sf::Keyboard::Right) {
            _mainView.move(15, 0);
            _entities["background"]->setPosition(
                _entities["background"]->getSprite().getPosition().x + 15,
                _entities["background"]->getSprite().getPosition().y);
            _x += 15;
        } else if (event.key.code == sf::Keyboard::Up) {
            _mainView.move(0, -15);
            _entities["background"]->setPosition(
                _entities["background"]->getSprite().getPosition().x,
                _entities["background"]->getSprite().getPosition().y - 15);
            _y -= 15;
        } else if (event.key.code == sf::Keyboard::Down) {
            _mainView.move(0, 15);
            _entities["background"]->setPosition(
                _entities["background"]->getSprite().getPosition().x,
                _entities["background"]->getSprite().getPosition().y + 15);
            _y += 15;
        } else if (event.key.code == sf::Keyboard::Num1) {
            _selectedEntity = "flyer";
        } else if (event.key.code == sf::Keyboard::Num2) {
            _selectedEntity = "OrangeRobot";
        } else if (event.key.code == sf::Keyboard::Num3) {
            _selectedEntity = "GreenRobot";
        } else if (event.key.code == sf::Keyboard::Num4) {
            _selectedEntity = "bomberman";
        } else if (event.key.code == sf::Keyboard::Num5) {
            _selectedEntity = "worm";
        } else if (event.key.code == sf::Keyboard::Num6) {
            _selectedEntity = "dropper";
        } else if (event.key.code == sf::Keyboard::Num7) {
            _selectedEntity = "CircularRobot";
        } else if (event.key.code == sf::Keyboard::Num8) {
            _selectedEntity = "boss1";
        } else if (event.key.code == sf::Keyboard::Num9) {
            _selectedEntity = "boss2";
        } else if (event.key.code == sf::Keyboard::Num0) {
            _selectedEntity = "wall1";
        } else if (event.key.code == sf::Keyboard::Dash) {
            _selectedEntity = "wall2";
        } else if (event.key.code == sf::Keyboard::Equal) {
            _selectedEntity = "wall3";
        } else if (event.key.code == sf::Keyboard::S) {
            _savingMode = true;
        }
    }
}

void Editor::mouseEvent(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            _window->setView(_menuView);
            sf::Vector2i mousePosition = sf::Mouse::getPosition(*_window);

            sf::Vector2f worldPosition =
                _window->mapPixelToCoords(mousePosition);

            if (_saveButton->getSprite().getGlobalBounds().contains(
                    worldPosition)) {
                _savingMode = true;
                return;
            }
            if (_music1->getSprite().getGlobalBounds().contains(
                    worldPosition)) {
                _musics["music2"].stop();
                _musics["music1"].play();
                _selectedMusic = "level1.ogg";
                return;
            }
            if (_music2->getSprite().getGlobalBounds().contains(
                    worldPosition)) {
                _musics["music1"].stop();
                _musics["music2"].play();
                _selectedMusic = "level2.ogg";
                return;
            }
            _window->setView(_mainView);
            mousePosition = sf::Mouse::getPosition(*_window);

            worldPosition = _window->mapPixelToCoords(mousePosition);
            _entities[_selectedEntity +
                      std::to_string(_entityQuantity[_selectedEntity])] =
                std::make_unique<EntitySFML>(_ressourceManager);
            _entities[_selectedEntity +
                      std::to_string(_entityQuantity[_selectedEntity])]
                ->setTexture(_selectedEntity + ".png");
            _entities[_selectedEntity +
                      std::to_string(_entityQuantity[_selectedEntity])]
                ->setPosition(
                    worldPosition.x - _entitiesSelectMenu[_selectedEntity]
                                              ->getSprite()
                                              .getLocalBounds()
                                              .width /
                                          2,
                    worldPosition.y - _entitiesSelectMenu[_selectedEntity]
                                              ->getSprite()
                                              .getLocalBounds()
                                              .height /
                                          2);
            _entities[_selectedEntity +
                      std::to_string(_entityQuantity[_selectedEntity])]
                ->setRect(std::get<0>(_entitiesRect[_selectedEntity]),
                          std::get<1>(_entitiesRect[_selectedEntity]));
            _entityQuantity[_selectedEntity]++;
        } else if (event.mouseButton.button == sf::Mouse::Right) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(*_window);
            sf::Vector2f worldPosition =
                _window->mapPixelToCoords(mousePosition);

            for (auto it = _entities.begin(); it != _entities.end();) {
                if (it->first == "background") {
                    it++;
                    continue;
                }
                if (it->second->getSprite().getGlobalBounds().contains(
                        worldPosition)) {
                    it = _entities.erase(it);
                    _entityQuantity[_selectedEntity]--;
                } else {
                    it++;
                }
            }
            for (auto entity : _entityQuantity) {
                if (entity.first == "background") {
                    continue;
                } else {
                    if (entity.second <= 0)
                        continue;
                    for (int j = 0; j <= entity.second; j++) {
                        if (_entities.find(entity.first + std::to_string(j)) ==
                            _entities.end()) {
                            for (int k = j + 1; k <= entity.second; k++) {
                                if (_entities.find(entity.first +
                                                   std::to_string(k)) !=
                                    _entities.end()) {
                                    _entities[entity.first +
                                              std::to_string(k - 1)] =
                                        std::move(_entities[entity.first +
                                                            std::to_string(k)]);
                                    _entities.erase(entity.first +
                                                    std::to_string(k));
                                }
                            }
                        } else
                            continue;
                    }
                }
            }
        }
    }
}

void Editor::update() {
    _texts["X"]->setString("x: " + std::to_string(_x));
    _texts["Y"]->setString("y: " + std::to_string(_y));
    _texts["name"]->setString(_selectedEntity);
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*_window);
    sf::Vector2f worldPosition = _window->mapPixelToCoords(mousePosition);
    _entitiesSelectMenu[_selectedEntity]->setPosition(
        worldPosition.x - _entitiesSelectMenu[_selectedEntity]
                                  ->getSprite()
                                  .getLocalBounds()
                                  .width /
                              2,
        worldPosition.y - _entitiesSelectMenu[_selectedEntity]
                                  ->getSprite()
                                  .getLocalBounds()
                                  .height /
                              2);
}

void Editor::saveLevel() {
    nlohmann::json level = JsonParser::readFile("rTypeLevels.json");

    int i = 1;
    level[_levelName] = {};
    level[_levelName]["Entity" + std::to_string(i)]["Type"] = "Background";
    i++;

    for (auto entity : _entityQuantity) {
        if (entity.first == "background" || entity.first == "wall1" ||
            entity.first == "wall2" || entity.first == "wall3") {
            continue;
        } else {
            if (entity.second <= 0)
                continue;
            level[_levelName]["Entity" + std::to_string(i)]["Count"] =
                entity.second;
            level[_levelName]["Entity" + std::to_string(i)]["Config"] =
                _entitiesJsonConfig[entity.first];
            for (int j = 0; j <= entity.second; j++) {
                if (entity.first == "background" ||
                    _entities.find(entity.first + std::to_string(j)) ==
                        _entities.end())
                    continue;
                level[_levelName]["Entity" + std::to_string(i)]["Positions"][j]
                     ["X"] = (int)_entities[entity.first + std::to_string(j)]
                                 ->getSprite()
                                 .getPosition()
                                 .x;
                level[_levelName]["Entity" + std::to_string(i)]["Positions"][j]
                     ["Y"] = (int)_entities[entity.first + std::to_string(j)]
                                 ->getSprite()
                                 .getPosition()
                                 .y;
            }
        }
        i++;
    }
    for (int j = 0; j <= _entityQuantity["wall1"]; j++) {
        if (_entities.find("wall1" + std::to_string(j)) == _entities.end())
            continue;
        level[_levelName]["Entity" + std::to_string(i)]["Count"] =
            _entityQuantity["wall1"];
        level[_levelName]["Entity" + std::to_string(i)]["Config"] =
            _entitiesJsonConfig["wall1"];
        level[_levelName]["Entity" + std::to_string(i)]["Positions"][j]["X"] =
            (int)_entities["wall1" + std::to_string(j)]
                ->getSprite()
                .getPosition()
                .x;
        level[_levelName]["Entity" + std::to_string(i)]["Positions"][j]["Y"] =
            (int)_entities["wall1" + std::to_string(j)]
                ->getSprite()
                .getPosition()
                .y;
    }
    i++;

    for (int j = 0; j <= _entityQuantity["wall2"]; j++) {
        if (_entities.find("wall2" + std::to_string(j)) == _entities.end())
            continue;
        level[_levelName]["Entity" + std::to_string(i)]["Count"] =
            _entityQuantity["wall2"];
        level[_levelName]["Entity" + std::to_string(i)]["Config"] =
            _entitiesJsonConfig["wall2"];
        level[_levelName]["Entity" + std::to_string(i)]["Positions"][j]["X"] =
            (int)_entities["wall2" + std::to_string(j)]
                ->getSprite()
                .getPosition()
                .x;
        level[_levelName]["Entity" + std::to_string(i)]["Positions"][j]["Y"] =
            (int)_entities["wall2" + std::to_string(j)]
                ->getSprite()
                .getPosition()
                .y;
    }
    i++;

    for (int j = 0; j <= _entityQuantity["wall3"]; j++) {
        if (_entities.find("wall3" + std::to_string(j)) == _entities.end())
            continue;
        level[_levelName]["Entity" + std::to_string(i)]["Count"] =
            _entityQuantity["wall3"];
        level[_levelName]["Entity" + std::to_string(i)]["Config"] =
            _entitiesJsonConfig["wall3"];
        level[_levelName]["Entity" + std::to_string(i)]["Positions"][j]["X"] =
            (int)_entities["wall3" + std::to_string(j)]
                ->getSprite()
                .getPosition()
                .x;
        level[_levelName]["Entity" + std::to_string(i)]["Positions"][j]["Y"] =
            (int)_entities["wall3" + std::to_string(j)]
                ->getSprite()
                .getPosition()
                .y;
    }

    level[_levelName]["Music"]["File"] = _selectedMusic;

    std::string jsonString = level.dump(2);
    std::cout << jsonString << std::endl;
    std::ofstream file("./config/r-type/rTypeLevels.json");
    file << jsonString;
}

void Editor::getInput() {
    sf::Font font;
    font.loadFromFile(std::string("font/arial.ttf"));
    sf::Text text;
    text.setFont(font);
    text.setString(
        "Level name:\nIt must be Level-1, Level-2, etc...\n\n\n\nOnce you have "
        "entered the "
        "name,\npress Enter to save or Escape to cancel.");
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(
        sf::Vector2f(_inputs["levelName"]->getSpritePosition().x + 120,
                     _inputs["levelName"]->getSpritePosition().y + 10));
    text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2,
                                text.getLocalBounds().height / 2));

    sf::Text text2;
    text2.setFont(font);
    text2.setString("Invalid level name");
    text2.setCharacterSize(20);
    text2.setFillColor(sf::Color::Red);
    text2.setPosition(
        sf::Vector2f(_inputs["levelName"]->getSpritePosition().x + 100,
                     _inputs["levelName"]->getSpritePosition().y + 130));
    text2.setOrigin(sf::Vector2f(text2.getLocalBounds().width / 2,
                                 text2.getLocalBounds().height / 2));
    bool invalidName = false;

    _inputs["levelName"]->setFont(font);
    _entities["background"]->setPosition(0, 0);

    sf::Event event;
    while (_window->isOpen()) {
        while (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _window->close();
            }
            for (auto& input : _inputs) {
                input.second->eventHandler(event, *_window);
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    if (_inputs["levelName"]->getText() == "" ||
                        _inputs["levelName"]->getText().substr(0, 6) !=
                            "Level-" ||
                        _inputs["levelName"]
                                ->getText()
                                .substr(
                                    6,
                                    _inputs["levelName"]->getText().size() - 6)
                                .find_first_not_of("0123456789") !=
                            std::string::npos) {
                        invalidName = true;
                    } else {
                        _levelName = _inputs["levelName"]->getText();
                        saveLevel();
                        _savingMode = false;
                        _entities["background"]->setPosition(_x, _y);
                        return;
                    }
                }
                if (event.key.code == sf::Keyboard::Escape) {
                    _savingMode = false;
                    _entities["background"]->setPosition(_x, _y);
                    return;
                }
            }
        }
        _window->draw(_entities["background"]->getSprite());
        for (auto& input : _inputs) {
            input.second->draw(*_window);
        }
        if (invalidName)
            _window->draw(text2);
        _window->draw(text);
        _window->display();
    }
}

void Editor::mainloop() {
    while (_window->isOpen()) {
        sf::Event event;
        _window->setView(_mainView);
        while (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _window->close();
            }
            keyEvent(event);
            mouseEvent(event);
        }
        update();
        _window->clear();
        _window->draw(_entities["background"]->getSprite());
        for (auto& entity : _entities) {
            if (entity.first == "background")
                continue;
            _window->draw(entity.second->getSprite());
        }
        _window->draw(_entitiesSelectMenu[_selectedEntity]->getSprite());
        _window->setView(_menuView);
        for (auto& text : _texts) {
            _window->draw(*text.second);
        }
        for (auto& text : _texts) {
            _window->draw(*text.second);
        }
        _window->draw(_saveButton->getSprite());
        _window->draw(_music1->getSprite());
        _window->draw(_music2->getSprite());
        if (_savingMode) {
            getInput();
        }
        _window->display();
    }
}
