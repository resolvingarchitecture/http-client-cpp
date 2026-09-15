add_executable(http_client_tests
    test_main.cpp
    test_url.cpp
    test_request.cpp
    test_response.cpp
    test_client.cpp
)
target_include_directories(http_client_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../third_party)
target_link_libraries(http_client_tests PRIVATE http_client)

find_package(Threads REQUIRED)
target_link_libraries(http_client_tests PRIVATE Threads::Threads)

include(CTest)
add_test(NAME http_client_tests COMMAND http_client_tests)
