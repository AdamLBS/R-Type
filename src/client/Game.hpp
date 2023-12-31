/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** Game.hpp
*/

#pragma once

#include <map>
#include <mutex>
#include <queue>
#include <sstream>
#include <thread>
#include "../global/EventHandler.hpp"
#include "../global/JsonParser.hpp"
#include "../global/ThreadPool.hpp"
#include "IEntity.hpp"
#include "Parser.hpp"
#include "ProgressBar.hpp"
#include "UDPClient.hpp"
#include <memory>

// #include <concurrent_vector.h>
class TCPClientImpl;

class InstanceMenu;

class IDisplay;

class Game {
   public:
    enum Lib {
        SDL,
        SFML,
    };

    Game();

    ~Game();

    void run(std::shared_ptr<sf::RenderWindow> window);

    void update(std::map<int, std::shared_ptr<IEntity>>* entitiesCopy);

    void handleEvent();

    bool connectToServer(std::string host, int port);

    bool connectToUdpServer(std::string host, int port);

    void setConnected(bool state) { isTCPClientConnected = state; };

    bool findEntity(int id);

    void addEntity(IEntity::EntityInfos entityInfos);

    void removeEntity(int id);

    void LoopUDPMessages();

    void setPlayerId(int id);

    std::string getHost() { return _host; };

    void flipEntity(Event evt);

    void setLib(int lib);

    void setLibToUse();

    void handleReceivedEvent(Event evt);

    void updateSprite(Event evt);

    void updateText(Event evt);

    void updateSound(Event evt);

    void joinGame(Event evt);

    void loopEventQueue();

    int getEntitiesNumber();

    void checkEntities(int nb);

    void animate(std::map<int, std::shared_ptr<IEntity>>* entitiesCopy);

    InstanceMenu* getInstanceMenu() { return _instanceMenu.get(); };

    std::shared_ptr<TCPClientImpl> getClient() { return _client; };

    void sendQuitEvent();

    void setUDPClientConnecting(bool state) { isUDPClientConnecting = state; };

    void clearUDPClient();

    void setClosed(bool state) { closed = state; };

   private:
    sf::View _view;
    sf::Clock _clock;
    std::shared_ptr<TCPClientImpl> _client;
    std::shared_ptr<UDPClient> _udpClient;
    int _event_indicator;
    std::queue<std::vector<uint8_t>> _queue;
    ThreadPool _threadPool;
    bool isTCPClientConnected = false;
    bool isUDPClientConnected = false;
    bool isUDPClientConnecting = false;
    bool closed;
    std::string _gameTitle;
    int _width;
    int _height;
    std::map<int, std::shared_ptr<IEntity>> _entities;
    int _playerId;
    std::string _host;
    ProgressBar _progressBar;
    std::unique_ptr<IDisplay> _display;
    Lib _lib;
    std::mutex entityMutex;
    std::vector<int> _entitiesToRemove;
    Parser parseRef;
    std::unique_ptr<InstanceMenu> _instanceMenu;
};
