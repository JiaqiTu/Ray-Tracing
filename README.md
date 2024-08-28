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

    This will generate the executables in the `build` directory.

## Running camera_gradient  

Once the project is built, you can run the programs and generate the output files:

- **Run `camera_gradient_v1` to produce `camera_gradient.ppm`:**

    ```bash
    build/camera_gradient_v1 > camera_gradient.ppm
    ```


## Running Ray-Sphere Intersection

In ray tracing, determining if and where a ray intersects a sphere is crucial. The equation for a sphere of radius \( r \) centered at a point \( \mathbf{C} \) is:

\[
(\mathbf{C} - \mathbf{P}) \cdot (\mathbf{C} - \mathbf{P}) = r^2
\]

To find out if a ray \( \mathbf{P}(t) = \mathbf{Q} + t\mathbf{d} \) intersects the sphere, we substitute \( \mathbf{P}(t) \) into the sphere equation:

\[
(\mathbf{C} - (\mathbf{Q} + t\mathbf{d})) \cdot (\mathbf{C} - (\mathbf{Q} + t\mathbf{d})) = r^2
\]

This expands and simplifies to a quadratic equation in \( t \):

\[
t^2(\mathbf{d} \cdot \mathbf{d}) - 2t(\mathbf{d} \cdot (\mathbf{C} - \mathbf{Q})) + \left((\mathbf{C} - \mathbf{Q}) \cdot (\mathbf{C} - \mathbf{Q}) - r^2\right) = 0
\]

Solving this quadratic equation gives:

- \( a = \mathbf{d} \cdot \mathbf{d} \)
- \( b = -2(\mathbf{d} \cdot (\mathbf{C} - \mathbf{Q})) \)
- \( c = (\mathbf{C} - \mathbf{Q}) \cdot (\mathbf{C} - \mathbf{Q}) - r^2 \)

Using the quadratic formula, we can solve for \( t \):

\[
t = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}
\]

The discriminant \( b^2 - 4ac \) determines the nature of the intersection:

- **Positive**: Two intersection points (the ray hits the sphere twice).
- **Zero**: One intersection point (the ray grazes the sphere).
- **Negative**: No intersection (the ray misses the sphere).

This geometric interpretation directly relates to the algebra, making it an essential concept in ray tracing.


- **Run `raytraced_image_v2` to produce `raytraced.ppm`:**

    ```bash
    build/raytraced_image_v2 > raytraced.ppm
    ```

Each command will execute the respective program and redirect the output to a PPM image file.

## Viewing the Output

The output of the programs are PPM image files (`camera_gradient.ppm` and `raytraced.ppm`). You can view these files using any image viewer that supports the PPM format, or you can convert them to another format using tools like ImageMagick:

```bash
# Example command to convert PPM to PNG using ImageMagick
convert camera_gradient.ppm camera_gradient.png
convert raytraced.ppm raytraced.png