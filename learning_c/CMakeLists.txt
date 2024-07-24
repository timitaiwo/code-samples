cmake_minimum_required(VERSION 3.29.6)

project(learning_c
        VERSION 0.0.0
        DESCRIPTION "a collection of projects accumuated when learning the c programming language"
        LANGUAGES C)

add_executable(quiz
        quiz.c)

add_executable(player_struct
        player_struct.c)