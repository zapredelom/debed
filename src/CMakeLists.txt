add_library(draw_server STATIC draw_room.cpp
                               draw_server.cpp
                               draw_session.cpp
                               draw_update_raw_data.cpp)
target_link_libraries(draw_server PRIVATE boost::boost)