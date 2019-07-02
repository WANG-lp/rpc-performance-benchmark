find_package(Threads REQUIRED)
find_package(Protobuf REQUIRED)
find_package(GRPC REQUIRED)

add_executable(grpc-server grpc-server.cpp gen/echo.grpc.pb.cc gen/echo.pb.cc)
target_link_libraries(grpc-server Threads::Threads gRPC::grpc++ protobuf::libprotobuf )

add_executable(grpc-client grpc-client.cpp gen/echo.grpc.pb.cc gen/echo.pb.cc)
target_link_libraries(grpc-client Threads::Threads gRPC::grpc++ protobuf::libprotobuf )

add_executable(grpc-client-async grpc-client-async.cpp gen/echo.grpc.pb.cc gen/echo.pb.cc)
target_link_libraries(grpc-client-async Threads::Threads gRPC::grpc++ protobuf::libprotobuf )