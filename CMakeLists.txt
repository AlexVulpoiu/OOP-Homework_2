cmake_minimum_required(VERSION 3.15)
project(Tema2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Werror -g")

add_executable(Tema2 main.cpp Matrice.cpp Matrice.h Graf.cpp Graf.h Graf_complet.cpp Graf_complet.h Graf_antisimetric.cpp Graf_antisimetric.h Graf_turneu.cpp Graf_turneu.h)
