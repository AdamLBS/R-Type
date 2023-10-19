/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** Core
*/

#pragma once
#include "Engine.hpp"
#include "IGame.hpp"
#include "Protocol.hpp"
#include "../server/ThreadSafeQueue.hpp"
#include "../server/UDPServer.hpp"

class Core
{
public:
    Core(UDPServer *server);
    ~Core();

    void mainLoop(ThreadSafeQueue<Event> &events, UDPServer *server);
    std::shared_ptr<Engine> getEngine() { return _engine; }
    std::shared_ptr<IGame> getGame() { return _game; }
    void getAllEntitiesToCreate(UDPServer *server, std::vector<Client>::iterator client);
    bool isReset() { return _game->isReset(); }
    void setReset(bool reset) { _game->setReset(reset); }

private:
    std::shared_ptr<Engine> _engine;
    std::shared_ptr<IGame> _game;
    std::chrono::high_resolution_clock::time_point _lastFrameTime;
};