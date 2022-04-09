file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/include/*.h")
file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.c")
add_library(game_lib ${SOURCE_LIST})
target_include_directories(game_lib PUBLIC ../include)
target_link_libraries(game_lib PUBLIC flecs_static)
target_link_libraries(game_lib PUBLIC raylib)
target_link_libraries(game_lib PUBLIC stc)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
