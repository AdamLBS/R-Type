// UDPClient.hpp

#ifndef HEADER_UDPCLIENT
#define HEADER_UDPCLIENT
#include "UDPConnection.hpp"
#include <thread>

template <typename T>
class UDPClient
{
public:
    UDPClient()
    {
    }

    void ConnectToServer(std::string &host, int port)
    {
        m_serverEndpoint = boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(host), port);
        m_connection = std::make_unique<UDPConnection<T>>(UDPConnection<T>(m_context, m_qMessagesIn, m_serverEndpoint));
        m_connection->StartListening();
        std::cout << "UDPClient connected to " << host << ":" << port << std::endl;
        thrContext = std::thread([this]() { m_context.run(); });

    }

    void Send(const message<T>& msg)
    {
        m_connection->Send(msg, GetServerEndpoint());
    }

    ThreadSafeQueue<owned_message_udp<T>>& Incoming()
    {
        return m_qMessagesIn;
    }

    boost::asio::ip::udp::endpoint& GetServerEndpoint()
    {
        return m_serverEndpoint;
    }

private:
    std::unique_ptr<UDPConnection<T>> m_connection;
    boost::asio::io_context m_context;
    boost::asio::ip::udp::endpoint m_serverEndpoint;
    ThreadSafeQueue<owned_message_udp<T>> m_qMessagesIn;
    std::string _host;
    int _port;
    std::thread thrContext;
};

#endif /* !HEADER_UDPCLIENT */
