#ifndef HEADER_UDPCONNECTION
#define HEADER_UDPCONNECTION

#include <boost/asio.hpp>
#include "../global/EventHandler.hpp"
#include "ThreadSafeQueue.hpp"
#include "Messages.hpp"
#include "Game.hpp"

using namespace boost::asio;

template <typename T>
class UDPConnection : public std::enable_shared_from_this<UDPConnection<T>>
{
public:
    UDPConnection(boost::asio::io_context& ioContext, ThreadSafeQueue<owned_message<T>>& qMessagesIn, boost::asio::ip::udp::endpoint& endpoint)
        : m_socket(ioContext, endpoint, 0),
          m_qMessagesIn(qMessagesIn)
    {
    }

    void StartListening()
    {
        Receive();
    }
    void Send(const message<T>& msg, boost::asio::ip::udp::endpoint endpoint)
    {
        m_socket.send_to(boost::asio::buffer(&msg, sizeof(msg)), endpoint);
    }
private:
    void Receive()
    {
        m_socket.async_receive_from(boost::asio::buffer(&m_msgTemporaryIn, sizeof(message<T>)), m_senderEndpoint,
                                    [this](const boost::system::error_code& ec, std::size_t length)
                                    {
                                        if (!ec && length > 0)
                                        {
                                            m_qMessagesIn.push_back({nullptr, m_msgTemporaryIn});
                                            Receive(); // Continue listening
                                        }
                                        else
                                        {
                                            // Handle error or stop listening
                                        }
                                    });
    }

private:
    boost::asio::ip::udp::socket m_socket;
    boost::asio::ip::udp::endpoint m_senderEndpoint;
    ThreadSafeQueue<owned_message<T>> &m_qMessagesIn;
    message<T> m_msgTemporaryIn;
};

#endif /* !HEADER_UDPCONNECTION */
