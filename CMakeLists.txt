cmake_minimum_required(VERSION 3.5)

project(concordo VERSION 1.0 LANGUAGES CXX)

include_directories (include)

file(GLOB_RECURSE SOURCE_FILES
    "src/*.cpp"
)

add_executable( concordo  ${SOURCE_FILES} "src/CanalVoz.cpp")

set_property(TARGET concordo PROPERTY CXX_STANDARD 20)