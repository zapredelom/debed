#pragma once
#include <boost/asio.hpp>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <set>
#include <utility>

#include "draw_room.h"


class DrawServer {
public:
    DrawServer(boost::asio::io_context& io_context, const boost::asio::ip::tcp::endpoint& endpoint);

private:
    void do_accept();
private:
    boost::asio::ip::tcp::acceptor acceptor_;
    DrawRoom room_;
};

