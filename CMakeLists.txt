cmake_minimum_required(VERSION 3.16)
project(http_client LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# The envelope Send() reads/writes is ra::common::Envelope, so http-client-cpp
# depends on its ra-common-cpp sibling directly - mirroring http-client-java
# depending only on ra-common (see DESIGN.md).
set(RA_COMMON_BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../common/ra-common-cpp ${CMAKE_CURRENT_BINARY_DIR}/ra-common-cpp)

find_package(OpenSSL REQUIRED)

# Header-only library.
add_library(http_client INTERFACE)
target_include_directories(http_client INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(http_client INTERFACE ra_common OpenSSL::SSL OpenSSL::Crypto)
target_compile_features(http_client INTERFACE cxx_std_20)

option(HTTP_CLIENT_BUILD_TESTS "Build http-client-cpp tests" ON)
if(HTTP_CLIENT_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
