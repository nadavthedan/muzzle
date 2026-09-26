# Define the application binary target
add_executable(muzzle_app
    main.cpp
)

# Link against the core library alias.
# PUBLIC include paths and dependencies from muzzle::lib (like FTXUI)
# propagate automatically without extra configuration here.
target_link_libraries(muzzle_app
    PRIVATE
        muzzle::lib
)

# Keep the binary at the top of the build tree (build/muzzle_app) instead of the
# default build/apps/muzzle_app that add_subdirectory() would otherwise produce.
set_target_properties(muzzle_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
