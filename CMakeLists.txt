cmake_minimum_required(VERSION 3.31)
project(Projet_Morpion)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")
add_executable(Projet_Morpion main.cpp
        Player.cpp
        Player.h
        jeu.cpp
        jeu.h
        tests.cpp
        tests.h)
