
include(FetchContent)

FetchContent_Declare(
  gRPC
  GIT_REPOSITORY https://github.com/grpc/grpc
  GIT_TAG        v1.28.0
  )
set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(gRPC)

find_package(Threads REQUIRED)
#find_package(Protobuf REQUIRED)
#find_package(GRPC REQUIRED)

add_executable(grpc-server grpc-server.cpp gen/echo.grpc.pb.cc gen/echo.pb.cc)
target_link_libraries(grpc-server Threads::Threads grpc++ )

add_executable(grpc-client grpc-client.cpp gen/echo.grpc.pb.cc gen/echo.pb.cc)
target_link_libraries(grpc-client Threads::Threads grpc++ )

add_executable(grpc-client-async grpc-client-async.cpp gen/echo.grpc.pb.cc gen/echo.pb.cc)
target_link_libraries(grpc-client-async Threads::Threads grpc++ )