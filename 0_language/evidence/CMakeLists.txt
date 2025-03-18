add_compile_definitions(SOURCE_ROOT_PATH="${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(0_filesystem src/filesystem.cpp include/filesystem.hpp include/utilities.hpp)

target_include_directories(0_filesystem
    PUBLIC
        $<BUILD_INTERFACE:
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}
        >
        $<INSTALL_INTERFACE:include/>
)
