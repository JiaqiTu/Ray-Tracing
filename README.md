# RayTracing Project

## Overview

This project is a ray tracing implementation that sets up a camera and renders a gradient background. The code is written in C++ and uses CMake as the build system.

## Build Instructions

Follow the steps below to build the project:


1. **Configure the Build**

    Use CMake to configure the build system. 

    ```bash
    cmake -B build
    ```

2. **Build the Project**

    After configuring the build, compile the project: 

    ```bash
    cmake --build build
    ```

    This will generate the executable `camera_gradient_v1` in the build directory.

3. **Running the Program**

    To run the program and generate the output file, use the following command:

    ```bash
    build/camera_gradient_v1 > camera_gradient.ppm
    ```

    This command will execute the `camera_gradient_v1` program and redirect the output to `camera_gradient.ppm`, which is a PPM image file.