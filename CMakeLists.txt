
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

# Set the build output directory (where the executable will be placed)
set(BUILD_OUTPUT_DIR ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})

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

# Add resource files
file(GLOB_RECURSE RESOURCE_FILES
    ${SOURCE_DIR}/*.frag
    ${SOURCE_DIR}/*.vert
    ${SOURCE_DIR}/*.rc
    ${SOURCE_DIR}/*.ttf
    ${SOURCE_DIR}/*.jpg
    ${SOURCE_DIR}/*.tga
    ${SOURCE_DIR}/*.obj
    ${SOURCE_DIR}/*.png
)

# Define the executable
add_executable(${TARGET_NAME} ${SOURCE_FILES} ${HEADER_FILES})

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

# Copy resource files to the build output directory
foreach(RESOURCE_FILE ${RESOURCE_FILES})
    # Get the directory part of the resource file
    get_filename_component(RESOURCE_DIRECTORY ${RESOURCE_FILE} DIRECTORY)
    # Compute the relative path from the SOURCE_DIR
    file(RELATIVE_PATH RESOURCE_RELATIVE_PATH ${SOURCE_DIR} ${RESOURCE_FILE})
    # Create the necessary directory structure in the build directory
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory
        ${BUILD_OUTPUT_DIR}/${RESOURCE_DIRECTORY}
    )
    # Copy each resource file to the corresponding directory in the build directory
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${RESOURCE_FILE}
        ${BUILD_OUTPUT_DIR}/${RESOURCE_RELATIVE_PATH}
    )
endforeach()

# Set up configurations
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${TARGET_NAME} PRIVATE -DDEBUG)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(${TARGET_NAME} PRIVATE -DNDEBUG)
endif()

