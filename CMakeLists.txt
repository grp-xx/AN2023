cmake_minimum_required(VERSION 3.0.0)
project(npl VERSION 0.1.0)
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

include_directories(/usr/local/include)
include_directories(lib/libnpl)
include_directories(lib/nlohmann)

link_directories(/usr/local/lib)

if (UNIX AND NOT APPLE)
    set (LINUX TRUE)
endif()
include(CTest)
enable_testing()

add_executable(UDPsrv src/UDPsrv.cpp)
add_executable(UDPclt src/UDPclt.cpp)
add_executable(TCPclt src/TCPclt.cpp)
add_executable(TCPnaive src/TCPsrvnaive.cpp)
add_executable(TCPsrv src/TCPsrv.cpp)
add_executable(TCPmt src/TCPmt.cpp)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
