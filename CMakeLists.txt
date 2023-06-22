cmake_minimum_required(VERSION 3.16)

project(getrekt LANGUAGES CXX)

add_executable(getrekt rectangle.cpp)
set_target_properties(getrekt PROPERTIES LINK_FLAGS "--bind -s ERROR_ON_UNDEFINED_SYMBOLS=0 -s ENVIRONMENT=web")
