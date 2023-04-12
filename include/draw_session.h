#pragma once
#include <boost/asio.hpp>
#include <memory>
#include <deque>

#include "draw_update_raw_data.h"
class DrawRoom;

class DrawParticipant {
public:
    using DrawUpdateRawData = DrawUpdateRawData;
    using DrawUpdateQueue = std::deque<DrawUpdateRawData>;

    virtual ~DrawParticipant() {}
    virtual void deliver(const DrawUpdateRawData& msg) = 0;
};

class DrawSession : public DrawParticipant, public std::enable_shared_from_this<DrawSession> {
public:
    DrawSession(boost::asio::ip::tcp::socket socket, DrawRoom& room);

    void start();
    void deliver(const DrawUpdateRawData& msg);

private:
    void do_read_header();
    void do_read_body();
    void do_write();

private:
    boost::asio::ip::tcp::socket socket_;
    DrawRoom& room_;
    DrawUpdateRawData read_msg_;
    DrawUpdateQueue write_msgs_;
};
