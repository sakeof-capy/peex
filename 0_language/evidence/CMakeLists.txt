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

add_executable(0_date_n_time src/data_n_time.cpp include/utilities.hpp)

target_include_directories(0_date_n_time
    PUBLIC
        $<BUILD_INTERFACE:
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}
        >
        $<INSTALL_INTERFACE:include/>
)

add_executable(0_regular_expressions src/regular_expressions.cpp include/utilities.hpp)

target_include_directories(0_regular_expressions
    PUBLIC
        $<BUILD_INTERFACE:
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}
        >
        $<INSTALL_INTERFACE:include/>
)

add_executable(0_mathematical_operations src/mathematical_operations.cpp include/utilities.hpp)

target_include_directories(0_mathematical_operations
    PUBLIC
        $<BUILD_INTERFACE:
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}
        >
        $<INSTALL_INTERFACE:include/>
)

add_executable(0_exceptions src/exceptions.cpp include/utilities.hpp)

target_include_directories(0_exceptions
    PUBLIC
        $<BUILD_INTERFACE:
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}
        >
        $<INSTALL_INTERFACE:include/>
)
