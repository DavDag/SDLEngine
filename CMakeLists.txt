cmake_minimum_required(VERSION 3.17)
project(SDLEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/ext/SDL2-2.0.14/x86_64-w64-mingw32/include/SDL2)
link_directories(${PROJECT_SOURCE_DIR}/ext/SDL2-2.0.14/x86_64-w64-mingw32/lib)

include_directories(${PROJECT_SOURCE_DIR}/ext/SDL2_image/include)
link_directories(${PROJECT_SOURCE_DIR}/ext/SDL2_image/lib/x64)

include_directories(${PROJECT_SOURCE_DIR}/ext/SDL2_ttf/include)
link_directories(${PROJECT_SOURCE_DIR}/ext/SDL2_ttf/lib/x64)

set(SOURCE_FILES src/main.cpp)
add_executable(SDLEngine ${SOURCE_FILES})

target_link_libraries(SDLEngine SDL2main SDL2 SDL2_image SDL2_ttf)