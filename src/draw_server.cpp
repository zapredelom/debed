#include "draw_server.h"
#include <boost/asio.hpp>

using namespace boost::asio::ip;

DrawServer::DrawServer(boost::asio::io_context& io_context, const tcp::endpoint& endpoint)
    : acceptor_(io_context, endpoint) {
     do_accept();
}

void DrawServer::do_accept() {
    acceptor_.async_accept([this](boost::system::error_code ec, tcp::socket socket) {
        if (!ec) {
            std::make_shared<DrawSession>(std::move(socket), room_)->start();
        }

        do_accept();
    });
}
