find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})
find_package(Thrift REQUIRED)
include_directories(${THRIFT_INCLUDE_DIR})

add_executable(thrift-server thrift-server.cpp gen-cpp/Echo.cpp gen-cpp/echo_types.cpp gen-cpp/echo_constants.cpp)
target_link_libraries(thrift-server ${THRIFT_LIBRARIES} OpenSSL::SSL OpenSSL::Crypto Threads::Threads)

add_executable(thrift-client thrift-client.cpp gen-cpp/Echo.cpp gen-cpp/echo_types.cpp gen-cpp/echo_constants.cpp)
target_link_libraries(thrift-client ${THRIFT_LIBRARIES} OpenSSL::SSL OpenSSL::Crypto Threads::Threads)