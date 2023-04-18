#include "draw_room.h"


void DrawRoom::join(DrawParticipant_ptr participant) {
    participants_.insert(participant);
    for (auto& msg : recent_msgs_) participant->deliver(msg);
}

void DrawRoom::leave(DrawParticipant_ptr participant) { participants_.erase(participant); }

void DrawRoom::deliver(const DrawUpdateRawData& msg) {
    recent_msgs_.push_back(msg);
    while (recent_msgs_.size() > max_recent_msgs) recent_msgs_.pop_front();

    for (auto participant : participants_) participant->deliver(msg);
}
