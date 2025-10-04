cmake_minimum_required(VERSION 3.16)
project(Chaos LANGUAGES CXX)

set(CMAKE_OSX_DEPLOYMENT_TARGET "14.0")
set(CMAKE_OSX_ARCHITECTURES "arm64")
set(CMAKE_CXX_STANDARD 20)

# Tell CMake where SFML is installed
set(CMAKE_PREFIX_PATH "/usr/local/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio)

add_executable(chaos src/main.cpp)
target_compile_definitions(chaos PRIVATE GL_SILENCE_DEPRECATION)
target_link_libraries(chaos PRIVATE SFML::Graphics SFML::Audio "-framework OpenGL")
