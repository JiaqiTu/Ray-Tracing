# RayTracing Project

## Overview

This project is a ray tracing implementation that sets up a camera, ray source and renders a picture based on the camera's location. The code is written in C++ and uses CMake as the build system.

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




## Background - camera_gradient  

Once the project is built, you can run the programs and generate the output files:

- **Run `camera_gradient_v1` to produce `camera_gradient.ppm`:**

    ```bash
    build/camera_gradient_v1 > vector_diagram/camera_gradient.ppm
    ```


## Ray-Sphere Intersection

In ray tracing, determining if and where a ray intersects a sphere is crucial. The equation for a sphere of radius `r` centered at a point `C` is:

```math
(C - P) \cdot (C - P) = r^2
```

To find out if a ray `P(t) = Q + t * d` intersects the sphere, we substitute `P(t)` into the sphere equation:

```math
(C - (Q + t \cdot d)) \cdot (C - (Q + t \cdot d)) = r^2
```

This expands and simplifies to a quadratic equation in `t`:

```math
t^2 \cdot (d \cdot d) - 2t \cdot (d \cdot (C - Q)) + ((C - Q) \cdot (C - Q) - r^2) = 0
```

Solving this quadratic equation gives:

- `a = d ⋅ d`
- `b = -2 * (d ⋅ (C - Q))`
- `c = (C - Q) ⋅ (C - Q) - r^2`

Using the quadratic formula, we can solve for `t`:

```math
t = {-b \pm \sqrt{b^2 - 4ac}}/{2a}
```

The discriminant `b^2 - 4ac` determines whether the ray intersects the sphere:

- **Positive**: Two intersection points (the ray hits the sphere twice).
- **Zero**: One intersection point (the ray grazes the sphere).
- **Negative**: No intersection (the ray misses the sphere).

This geometric interpretation directly relates to the algebra, making it an essential concept in ray tracing.

