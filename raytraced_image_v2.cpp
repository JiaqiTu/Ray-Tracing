#include <iostream>
#include "color.h"
#include "vec3.h"
#include "ray.h"
#include "raytracing.h"
#include "hittable_list.h"
#include "sphere.h"
#include "hittable.h"
#include "camera.h"

// using hittable obj in the ray_color function to achieve the same result as hit_sphere function

// double hit_sphere(const point3& center, double radius, const ray& r) {
//     vec3 oc = center - r.origin();
//     auto a = dot(r.direction(), r.direction());
//     auto b = -2.0 * dot(r.direction(), oc);
//     auto c = dot(oc, oc) - radius*radius;
//     auto discriminant = b*b - 4*a*c;
//     // -x- placing a small sphere at −1 on the z-axis and then coloring red
    
//     if (discriminant < 0) {
//         return -1.0;
//     } else {
//         return (-b - std::sqrt(discriminant) ) / (2.0*a);
//     }
// }       



int main() {

   

    // World

    hittable_list world;

    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    // Camera

    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;


    // Render
    cam.render(world);
}
