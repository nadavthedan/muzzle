cmake_minimum_required(VERSION 3.25)
project(muzzle VERSION 1.0 LANGUAGES CXX)

# Enforce C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Export compile_commands.json for editor/LSP type support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Fetch the FTXUI library directly from GitHub
include(FetchContent)
FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
    GIT_TAG        main
)
FetchContent_MakeAvailable(ftxui)

# Define the executable target
add_executable(muzzle_app apps/main.cpp)

# Link the FTXUI library to the application
# PRIVATE visibility ensures downstream targets don't implicitly inherit this dependency
target_link_libraries(muzzle_app PRIVATE ftxui::ftxui)
