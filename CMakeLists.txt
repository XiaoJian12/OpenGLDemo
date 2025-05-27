cmake_minimum_required(VERSION 3.10)
project(GLDemo VERSION 1.0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 查找OpenGL包
find_package(OpenGL REQUIRED)

# 添加GLFW依赖
# 使用项目相对路径指定GLFW
set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/../packages/GLFW/include")
set(GLFW_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/../packages/GLFW/lib")

# 输出GLFW路径信息（调试用）
message(STATUS "GLFW Include Dir: ${GLFW_INCLUDE_DIR}")
message(STATUS "GLFW Library Dir: ${GLFW_LIBRARY_DIR}")

# 添加GLAD
# 设置GLAD源文件目录
set(GLAD_DIR ${CMAKE_SOURCE_DIR}/src/external/glad)

# 添加源文件
set(SOURCES
    src/main.cpp
    ${GLAD_DIR}/src/glad.c
    src/shader/shader.h
    src/shader/shader.cpp
    src/texture/texture.h
    src/texture/texture.cpp
)

# 添加头文件目录（全局）
include_directories(
    ${GLAD_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 设置目标特定的包含目录
target_include_directories(${PROJECT_NAME} PRIVATE
    ${GLFW_INCLUDE_DIR}
)

# 链接库
target_link_directories(${PROJECT_NAME} PRIVATE ${GLFW_LIBRARY_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE
    OpenGL::GL
    glfw3
)

# Windows特定设置
if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE gdi32 user32 shell32)
endif()

# 复制着色器和资源文件到输出目录（如果有）
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/src/shader/shaders $<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders
)

# 输出配置信息
message(STATUS "OpenGL Demo配置完成")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "输出目录: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")