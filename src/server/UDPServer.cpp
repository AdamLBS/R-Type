/*
** EPITECH PROJECT, 2023
** B-CPP-500-MAR-5-1-rtype-martin.ramdane
** File description:
** UDPServer
*/

#include "UDPServer.hpp"
#include "Server.hpp"

UDPServer::UDPServer(int port) : socket_(_io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port))
{
    _nbPlayers = 0;
    _clients = std::vector<Client>();
    try
    {
        std::cout << "Server listening on port " << port << std::endl;
        start_receive();
        _server_thread = std::thread([this]() { _io_service.run(); });
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error during server initialization: " << e.what() << std::endl;
    }
}

UDPServer::~UDPServer()
{
}

void UDPServer::start_receive()
{
    try
    {
        socket_.async_receive_from(boost::asio::buffer(recv_buffer_), remote_endpoint_,
                                   [this](const std::error_code &error, std::size_t bytes_recvd) {
                                    std::cout << "Received " << bytes_recvd << " bytes" << std::endl;
                                    start_receive();
                                    //    handler(error, bytes_recvd);
                                   });
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error starting receive: " << e.what() << std::endl;
    }
}

void UDPServer::handler(const std::error_code &error, std::size_t bytes_recvd)
{
    if (!error)
    {
        std::cout << "Received " << bytes_recvd << " bytes" << std::endl;
        start_receive();
    } else {
        std::cerr << "Error receiving data: " << error.message() << std::endl;
    }
}

void UDPServer::send_ping_to_clients()
{
    // while (true)
    // {
    //     mutex_.lock();
    //     for (auto it = clients_.begin(); it != clients_.end();)
    //     {
    //         std::cout << "Client " << it->client.address().to_string() << ":" << it->client.port() << " last ping: " << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - it->timestamp).count() << std::endl;
    //         if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - it->timestamp).count() > 5)
    //         {
    //             std::cout << "Client " << it->client.address().to_string() << ":" << it->client.port() << " timed out." << std::endl;
    //             it = clients_.erase(it);
    //         }
    //         else
    //         {
    //             socket_.send_to(boost::asio::buffer("Ping", 4), it->client);
    //             ++it;
    //         }
    //     }
    //     mutex_.unlock();
    //     std::this_thread::sleep_for(std::chrono::seconds(2));
    // }
}

void UDPServer::addClient(Client client)
{
    _clients.push_back(client);
    _nbPlayers++;
}

void UDPServer::removeClient(Client client)
{
    _clients.erase(std::remove_if(_clients.begin(), _clients.end(), [&client](const Client &c)
                                  { return c.client.address() == client.client.address() && c.client.port() == client.client.port(); }));
    _nbPlayers--;
}

void UDPServer::sendEvent(Event evt, const std::string &host, int port)
{
    message<ACTION> msg;
    std::cout << "send event" << std::endl;
    std::vector<uint8_t> data = encodeEvent(evt);
    boost::asio::ip::udp::endpoint remote_endpoint(boost::asio::ip::address::from_string(host), port);
    socket_.send_to(boost::asio::buffer(data), remote_endpoint);
}

std::vector<uint8_t> UDPServer::encodeEvent(Event event)
{
    EventHandler evt;
    evt.addEvent(event.ACTION_NAME, event.body_size, event.body);
    return evt.encodeMessage();
}

void UDPServer::handleEvents(Event evt)
{
    switch (evt.ACTION_NAME)
    {
        case ACTION::LEFT:
            std::cout << "Player go to left" << std::endl;
            break;
        case ACTION::RIGHT:
            std::cout << "Player go to right" << std::endl;
            break;
        case ACTION::UP:
            std::cout << "Player go to up" << std::endl;
            break;
        case ACTION::DOWN:
            std::cout << "Player go to down" << std::endl;
            break;
        case ACTION::SHOOT:
            std::cout << "Player shoot" << std::endl;
            break;
        default:
            break;
    }
}