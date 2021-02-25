cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/EngineLib/include)

include_directories(${PROJECT_SOURCE_DIR}/EngineLib/ext/SDL2/include)
link_directories(${PROJECT_SOURCE_DIR}/EngineLib/ext/SDL2/lib/SDL2)
link_directories(${PROJECT_SOURCE_DIR}/EngineLib/ext/SDL2/lib/SDL_image-2.0.5)
link_directories(${PROJECT_SOURCE_DIR}/EngineLib/ext/SDL2/lib/SDL_ttf)

set(SOURCE_FILES library.cpp)
add_library(EngineLib SHARED ${SOURCE_FILES})

target_link_libraries(EngineLib SDL2 SDL2_image SDL2_ttf)
