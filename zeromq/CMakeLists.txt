find_package(Threads REQUIRED)
find_package(ZeroMQ REQUIRED)
include_directories(${ZMQ_INCLUDE_DIRS})

add_executable(zeromq-server zeromq-server.cpp ZeroMQService.hpp)
target_link_libraries(zeromq-server ${ZMQ_LIBRARIES} Threads::Threads)

add_executable(zeromq-client zeromq-client.cpp ZeroMQService.hpp)
target_link_libraries(zeromq-client ${ZMQ_LIBRARIES} Threads::Threads)