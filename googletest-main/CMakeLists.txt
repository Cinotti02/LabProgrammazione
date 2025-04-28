project(G_Unit_Test)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run test1.cpp
        TestData.cpp
        TestTask.cpp
        TestCalendar.cpp
        TestUtility.cpp
        TestInterface.cpp
        TestToDoList.cpp
        ../Data.cpp
        ../Task.cpp
        ../Calendar.cpp
        ../nlohmann/json.hpp
        ../Utility.cpp
        ../Interface.cpp
        ../ToDoList.cpp
)

target_link_libraries(Google_Tests_run gtest gtest_main)