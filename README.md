# Samira3D

![](https://github.com/abhatem/Samira3D/blob/master/demo.gif)

## Description

An older project where I attempt to build a 3D graphics engine. The engine supports:
- Basic Lighting (directional and point lights)
- Shadows using shadow mapping (https://learnopengl.com/Advanced-Lighting/Shadows/Shadow-Mapping)
- Basic material system with color and normal maps
- Text rendering
- Skybox rendering
- A scene graph with an entity/component approach
- 3D Model loading using assimp (tested with obj files)
- Mouse and keyboard input

## Prerequisites

The following are required to compile this project:

- Visual Studio 2019 or later
- Windows SDK version 10.0
- C++ Desktop development workload in Visual Studio

## Dependencies

This project depends on the following libraries:

- Assimp 3.3.1
- FreeType
- GLM
- GLEW 2.1.0
- SFML 2.4.2

These libraries need to be installed and their paths should be set up correctly in the project properties. The paths in the project are currently set to `D:\libs\`, so if you install the libraries in a different location, you will need to update the paths accordingly.

## Compiling the Project

1. Open the solution file in Visual Studio.
2. Select the desired configuration (Debug or Release) and platform (Win32 or x64).
3. Build the solution by clicking on `Build -> Build Solution`.

## Running the Project

After building the project, you can run it by clicking on `Debug -> Start Debugging` for the Debug configuration or `Debug -> Start Without Debugging` for the Release configuration.
