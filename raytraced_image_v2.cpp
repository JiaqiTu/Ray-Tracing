#include <iostream>
#include "raytracing.h"
#include "color.h"
#include "vec3.h"
#include "ray.h"
#include "hittable_list.h"
#include "material.h"
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


    // // World + Material
    // auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    // auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
    // // auto material_left   = make_shared<metal>(color(0.8, 0.8, 0.8),0.3);
    // auto material_left   = make_shared<dielectric>(1/1.33);  //1.5 - glass    or   1/1.33 - air bubble in water
    // auto material_right  = make_shared<metal>(color(0.8, 0.6, 0.2),1);

    // world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    // world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.2),   0.5, material_center));
    // world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
    // world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));

    //test
    auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
    auto material_left   = make_shared<dielectric>(1.50);
    auto material_bubble = make_shared<dielectric>(1.00 / 1.50);
    auto material_right  = make_shared<metal>(color(0.8, 0.6, 0.2), 1.0);

    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.2),   0.5, material_center));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.4, material_bubble));
    world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));
    // Camera

    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;

    cam.vfov = 20;
    //add position feature
    cam.lookfrom = point3(-2,2,1);
    cam.lookat   = point3(0,0,-1);
    cam.vup      = vec3(0,1,0);

    // depth feature
    cam.defocus_angle = 10.0;
    cam.focus_dist    = 3.4;
    

    // Render
    cam.render(world);


}
