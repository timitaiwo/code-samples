cmake_minimum_required(VERSION 3.29.6)

project(wordle
        VERSION 0.1.0
        DESCRIPTION "a c implementation of wordle"
        LANGUAGES C)

add_executable(wordle
        wordle.c
        word_of_day.c)