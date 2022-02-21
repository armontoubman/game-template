add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} PUBLIC flecs_static)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib)
target_link_libraries(${PROJECT_NAME} PRIVATE game_lib)


# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} PUBLIC "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} PUBLIC "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} PUBLIC "-framework OpenGL")
endif()
