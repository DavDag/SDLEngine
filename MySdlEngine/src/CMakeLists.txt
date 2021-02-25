cmake_minimum_required(VERSION 3.17)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/MySdlEngine/include)

include_directories(${PROJECT_SOURCE_DIR}/MySdlEngine/ext/SDL2-2.0.14/include/SDL2)
include_directories(${PROJECT_SOURCE_DIR}/MySdlEngine/ext/SDL2_image-2.0.5/include/SDL2)
include_directories(${PROJECT_SOURCE_DIR}/MySdlEngine/ext/SDL2_mixer-2.0.4/include/SDL2)
include_directories(${PROJECT_SOURCE_DIR}/MySdlEngine/ext/SDL2_net-2.0.1/include/SDL2)
include_directories(${PROJECT_SOURCE_DIR}/MySdlEngine/ext/SDL2_ttf-2.0.15/include/SDL2)

link_directories(${PROJECT_SOURCE_DIR}/MySdlEngine/ext/SDL2-2.0.14/lib)
link_directories(${PROJECT_SOURCE_DIR}/MySdlEngine/ext/SDL2_image-2.0.5/lib)
link_directories(${PROJECT_SOURCE_DIR}/MySdlEngine/ext/SDL2_mixer-2.0.4/lib)
link_directories(${PROJECT_SOURCE_DIR}/MySdlEngine/ext/SDL2_net-2.0.1/lib)
link_directories(${PROJECT_SOURCE_DIR}/MySdlEngine/ext/SDL2_ttf-2.0.15/lib)

set(SOURCE_FILES library.cpp)
add_library(MSE_lib SHARED ${SOURCE_FILES})

set_target_properties(MSE_lib PROPERTIES PREFIX "")

target_link_libraries(MSE_lib SDL2 SDL2_image SDL2_mixer SDL2_net SDL2_ttf)
