cmake_minimum_required(VERSION 3.17)
project(flighters_c C)

find_package(raylib 2.5.0 REQUIRED) # Requires at least version 2.5.0

set(CMAKE_C_STANDARD 99)

set(source "${CMAKE_SOURCE_DIR}/resources")
set(destination "${CMAKE_CURRENT_BINARY_DIR}/resources")

file(GLOB_RECURSE SOURCE_FILES "src/*.c")

add_executable(flighters_c ${SOURCE_FILES})

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
        DEPENDS ${destination}
        COMMENT "symbolic link resources folder from ${source} => ${destination}"
)

target_link_libraries(flighters_c raylib)