
# Samira3D

![](https://github.com/abhatem/Samira3D/blob/master/demo.gif)

## Description

An older project where I attempt to build a 3D graphics engine. The engine supports:
- Basic Lighting (directional and point lights)
- Shadows using shadow mapping ([Learn OpenGL - Shadow Mapping](https://learnopengl.com/Advanced-Lighting/Shadows/Shadow-Mapping))
- Basic material system with color and normal maps
- Text rendering
- Skybox rendering
- A scene graph with an entity/component approach
- 3D Model loading using Assimp (tested with OBJ files)
- Mouse and keyboard input

## Prerequisites

### Windows

- Visual Studio 2019 or later
- Windows SDK version 10.0
- C++ Desktop development workload in Visual Studio

### Ubuntu

- A C++ compiler that supports C++17 (e.g., GCC 7 or later)
- CMake 3.10 or later

## Dependencies

This project depends on the following libraries:

- Assimp 3.3.1
- FreeType
- GLM
- GLEW 2.1.0
- SFML 2.4.2

### Windows

These libraries need to be installed, and their paths should be set up correctly in the project properties. The paths in the project are currently set to `D:\libs\`, so if you install the libraries in a different location, you will need to update the paths accordingly.

### Ubuntu

On Ubuntu, you can install these dependencies using `apt`:

```bash
sudo apt-get install libassimp-dev libfreetype6-dev libglm-dev libglew-dev libsfml-dev
```

## Compiling the Project

### Windows

1. Open the solution file in Visual Studio.
2. Select the desired configuration (Debug or Release) and platform (Win32 or x64).
3. Build the solution by clicking on `Build -> Build Solution`.

### Ubuntu

1. Open a terminal and navigate to the project's root directory.
2. Create a build directory:

"bash
mkdir build
cd build
"

3. Run CMake to configure the project:

"bash
cmake ..
"

4. Compile the project using `make`:

"bash
make
"

## Running the Project

### Windows

After building the project, you can run it by clicking on `Debug -> Start Debugging` for the Debug configuration or `Debug -> Start Without Debugging` for the Release configuration.

### Ubuntu

After compiling, you can run the project by navigating to the build directory and executing the binary:

"bash
./Samira3D
"

Make sure that the necessary resource files (e.g., `.tga`, `.obj`, `.png`) are correctly placed in the build directory as expected by the application.

