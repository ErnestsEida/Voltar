cmake_minimum_required(VERSION 3.20)
project(Voltar)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Important for static SFML
set(SFML_STATIC_LIBRARIES ON)

include_directories(${CMAKE_SOURCE_DIR}/includes)
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)


add_executable(executable main.cpp
    src/voltar/core.cpp
    src/voltar/logger.cpp
    src/voltar/core/scene.cpp
    src/voltar/core/instance.cpp
    src/voltar/internal/scene_manager.cpp
    src/voltar/internal/instance_manager.cpp
    src/voltar/graphics/base_drawable.cpp
)

# This defines SFML_STATIC for your project so headers behave correctly
target_compile_definitions(executable PRIVATE SFML_STATIC)

# Link SFML modules
target_link_libraries(executable PRIVATE
    SFML::Graphics
    SFML::Audio
    SFML::Network
    SFML::Window
    SFML::System
)
