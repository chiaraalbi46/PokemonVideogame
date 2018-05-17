add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(EXECUTABLE_NAME "runAllTests")

set(TEST_SOURCE_FILES ItemTests.cpp )
add_executable(${EXECUTABLE_NAME} runAllTests.cpp ItemTests.cpp PlayerTests.cpp CollisionTests.cpp PokemonTests.cpp)
target_link_libraries(runAllTests gtest gtest_main core)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
