cmake_minimum_required(VERSION 3.30)
project(LabProgrammazione)

set(JSON_BuildTests OFF CACHE INTERNAL "") # stai dicendo a cmake di non runnare i test

set(CMAKE_CXX_STANDARD 20)

add_executable(LabProgrammazione main.cpp
            Data.cpp
            Data.h
            Task.cpp
            Task.h
            Calendar.cpp
            Calendar.h
            nlohmann/json.hpp
        Utility.cpp
        Utility.h
        Interface.cpp
        Interface.h)