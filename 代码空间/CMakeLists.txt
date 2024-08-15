cmake_minimum_required(VERSION 3.15)

project(game_name)
set(CMAKE_CXX_STANDARD 11)

#依赖路径
set(EASYX_INCLUDE_DIR "E:/vs2022/VC/Auxiliary/VS/include/easyx.h")
set(EASYX_LIBRARY_DIR "E:/vs2022/VC/Auxiliary/VS/x64/EasyX*.lib")

#文件路径
file(GLOB_RECURSE SRC_LIST ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB RESOURCES "${PROJECT_SOURCE_DIR}/resources/*.mp3" "${PROJECT_SOURCE_DIR}/resources/*.png" "${PROJECT_SOURCE_DIR}/resources/*.wav" "${PROJECT_SOURCE_DIR}/resources/*.ttf")
include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(game ${SRC_LIST} ${RESOURCES})
# add_library(game SHARED ${SRC_LIST} ${RESOURCES})

target_link_libraries(game PUBLIC ${EASYX_INCLUDE_DIR})
target_link_directories(game PUBLIC ${EASYX_LIBRARY_DIR})
