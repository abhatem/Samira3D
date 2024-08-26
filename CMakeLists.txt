cmake_minimum_required(VERSION 3.10)

# Project name
project(Samira3D)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the target name
set(TARGET_NAME Samira3D)

# Set the source directory
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/Engine3)

# Find required packages
find_package(assimp REQUIRED)
find_package(Freetype REQUIRED)
find_package(glm REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

# Add source files
file(GLOB_RECURSE SOURCE_FILES
    ${SOURCE_DIR}/*.cpp
)

# Add header files
file(GLOB_RECURSE HEADER_FILES
    ${SOURCE_DIR}/*.h
)

# Add shaders and other resources
file(GLOB_RECURSE RESOURCE_FILES
    ${SOURCE_DIR}/*.frag
    ${SOURCE_DIR}/*.vert
    ${SOURCE_DIR}/*.rc
    ${SOURCE_DIR}/*.ttf
    ${SOURCE_DIR}/*.jpg
)

# Define the executable
add_executable(${TARGET_NAME} ${SOURCE_FILES} ${HEADER_FILES} ${RESOURCE_FILES})

# Link libraries
target_link_libraries(${TARGET_NAME}
    assimp::assimp
    Freetype::Freetype
    OpenGL::GL
    GLEW::GLEW
    glm::glm
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    sfml-network
)

# Set up configurations
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${TARGET_NAME} PRIVATE -DDEBUG)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(${TARGET_NAME} PRIVATE -DNDEBUG)
endif()
