include_directories(${PROJECT_SOURCE_DIR}/EngineLib/include)
link_directories(${PROJECT_SOURCE_DIR}/EngineLib/src)
add_executable(MainTest main.cpp)
target_link_libraries(MainTest EngineLib)
