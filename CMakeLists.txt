cmake_minimum_required(VERSION 3.31)
project(Projet_Morpion)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projet_Morpion main.cpp
        Player.cpp
        Player.h
        jeu.cpp
        jeu.h
        tests.cpp
        tests.h)
