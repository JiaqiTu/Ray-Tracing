#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
  public:
    sphere(const point3& center, double radius) : center(center), radius(std::fmax(0,radius)) {}

    // bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {

        vec3 oc = center - r.origin();
        auto a = r.direction().length_squared();
        auto h = dot(r.direction(), oc);
        auto c = oc.length_squared() - radius*radius;

        auto discriminant = h*h - a*c;
        if (discriminant < 0)
            return false;

        auto sqrtd = std::sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (h - sqrtd) / a;
        // if (root <= ray_tmin || ray_tmax <= root) {
        if (!ray_t.surrounds(root)) {

            root = (h + sqrtd) / a;
            // if (root <= ray_tmin || ray_tmax <= root)
            if (!ray_t.surrounds(root))
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        // rec.normal = (rec.p - center) / radius;
        vec3 outward_normal = (rec.p - center) / radius;
            //rec.p - center: This calculates a vector that points from the center of the sphere to the point of intersection (rec.p). 
            //The direction of this vector is from the center of the sphere outward toward the surface where the intersection occurs.
        rec.set_face_normal(r, outward_normal);

        return true;
    }

  private:
    point3 center;
    double radius;
};

#endif