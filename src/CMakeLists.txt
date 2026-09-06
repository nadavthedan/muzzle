# add all files in the library explicitly after muzzle_lib
add_library(muzzle_lib)

# Create a namespaced alias so internal targets link consistently
add_library(muzzle::lib ALIAS muzzle_lib)

# Configure include paths:
# PUBLIC means any target linking to muzzle_lib inherits this include directory
target_include_directories(muzzle_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link third-party libraries needed by the library logic
target_link_libraries(muzzle_lib
    PUBLIC
        ftxui::screen
        ftxui::dom
        ftxui::component
)

# Apply compiler warning flags cleanly to this target only
target_compile_options(muzzle_lib PRIVATE
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
)
