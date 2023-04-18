#pragma once

#include "draw_session.h"

#include <set>
#include <memory>
#include <deque>

class DrawRoom {
public:
    using DrawParticipant_ptr = std::shared_ptr<DrawParticipant> ;

    void join(DrawParticipant_ptr participant);

    void leave(DrawParticipant_ptr participant);
    void deliver(const DrawUpdateRawData& msg);

private:
    std::set<DrawParticipant_ptr> participants_;
    enum { max_recent_msgs = 100 };
    DrawParticipant::DrawUpdateQueue recent_msgs_;
};
