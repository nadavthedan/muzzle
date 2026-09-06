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
