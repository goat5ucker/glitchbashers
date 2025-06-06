cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

include(FetchContent)

set(CMAKE_BINARY_DIR ../sauce/)
set(CMAKE_SOURCE_DIR ../sauce/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../output/)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(ImGui
    GIT_REPOSITORY https://github.com/ocornut/imgui
    GIT_TAG v1.91.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(ImGui)
FetchContent_GetProperties(ImGui SOURCE_DIR IMGUI_DIR)
set(IMGUI_SFML_FIND_SFML OFF)

FetchContent_Declare(ImGui-SFML
    GIT_REPOSITORY https://github.com/SFML/imgui-sfml
    GIT_TAG v3.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(ImGui-SFML)

add_executable(glitchbashers sauce/main.cpp)

target_compile_features(glitchbashers PRIVATE cxx_std_17)
target_link_libraries(glitchbashers PRIVATE SFML::Graphics ImGui-SFML::ImGui-SFML)
target_include_directories(glitchbashers PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/sauce)