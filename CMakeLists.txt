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
    GIT_TAG        v7.0.3
    GIT_PROGRESS   TRUE
    GIT_SHALLOW    TRUE
    EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(ftxui)

# The library layer must be configured after FTXUI, since it links against
# the ftxui:: targets that FetchContent makes available above.
add_subdirectory(src)
add_subdirectory(apps)
