/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** UDPServer
*/

#pragma once
#include <boost/asio.hpp>
#include <iostream>
#include <utility>
#include <chrono>
#include <thread>
#include "Mutex.hpp"
#include "../global/EventHandler.hpp"

class Instance;

struct Client
{
    boost::asio::ip::udp::endpoint client;
    std::chrono::system_clock::time_point timestamp;
};

class UDPServer
{
public:
    UDPServer(int port);
    ~UDPServer();
    void setInstance(Instance *instance) { _instanceRef = instance; }
    void addClient(Client client);
    void removeClient(Client client);
    int getNbPlayers() const { return _nbPlayers; }
    void sendEvent(Event evt, const std::string &host, int port);
    std::vector<uint8_t> encodeEvent(Event event);
    void handleEvents(Event evt);

private:
    void start_receive();
    void handler(const std::error_code &error, std::size_t bytes_recvd);
    void send_ping_to_clients();
    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint remote_endpoint_;
    std::vector<Client> clients_;
    std::vector<uint8_t> recv_buffer_ = std::vector<uint8_t>(1024);
    std::thread _server_thread;
    std::vector<Client> _clients;
    int _nbPlayers;
    Mutex mutex_;
    Instance *_instanceRef;
    boost::asio::io_service _io_service;
};
