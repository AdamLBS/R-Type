/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** Game.hpp
*/

#pragma once
#include <map>
#include <sstream>
#include "Entity.hpp"
#include "RessourceManager.hpp"
#include "Parser.hpp"
#include "JsonParser.hpp"
#include "TCPClientImpl.hpp"
// #include "UDPClientImpl.hpp"
#include "../global/EventHandler.hpp"
#include <thread>
#include <queue>
#include "ThreadPool.hpp"
class TCPClientImpl;
// class UDPClientImpl;
class Game
{
public:
    Game();
    ~Game(){};
    void run();
    void createWindow(std::string name, int x, int y);
    void animate();
    void draw();
    void handleEvent();
    void update();
    void getinfos(){};
    bool connectToServer(std::string host, int port);
    bool connectToUdpServer(std::string host, int port);
    void setConnected(bool) { isTCPClientConnected = true; }

private:
    sf::RenderWindow _window;
    sf::View _view;
    sf::Event _event;
    sf::Clock _clock;
    RessourceManager _ressourceManager;
    Parser _parser;
    TCPClientImpl *_client;
    // UDPClientImpl *_udpClient;
    int _event_indicator;
    std::queue<std::vector<uint8_t>> _queue;
    ThreadPool _threadPool;
    // bool isInstanceConnected = false;
    bool isTCPClientConnected = false;
    bool isUDPClientConnected = false;
    bool closed;
};