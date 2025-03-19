add_compile_definitions(SOURCE_ROOT_PATH="${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(1_json_parsing src/json.cpp)
target_link_libraries(1_json_parsing PRIVATE nlohmann_json::nlohmann_json)

add_executable(1_xml_parsing src/xml.cpp)
target_link_libraries(1_xml_parsing PRIVATE pugixml::pugixml)
