#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::make_shared;
using std::shared_ptr;

class hittable_list : public hittable {
  public:
    std::vector<shared_ptr<hittable>> objects;

    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) { add(object); }

    void clear() { objects.clear(); }

    void add(shared_ptr<hittable> object) {
        objects.push_back(object);
    }

    // bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) 
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        hit_record temp_rec;
        bool hit_anything = false;
        // auto closest_so_far = ray_tmax;
        auto closest_so_far = ray_t.max;

        for (const auto& object : objects) {
            // if (object->hit(r, ray_tmin, closest_so_far, temp_rec)) {
            if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
};

#endif


//The hit function in the hittable_list class is responsible for determining whether a ray intersects with any of the objects in a list of hittable objects. 
// ray& r: This is the ray that is being tested for intersections with objects in the list.
// interval ray_t: This is an interval representing the range of t values along the ray. The t value is a parameter that moves the point P(t) along the ray, where P(t) = origin + t * direction. The interval specifies the range of t values within which intersections are considered valid.
// hit_record& rec: This is a structure that stores information about the closest intersection point found so far, such as the point of intersection, the surface normal at that point, and the t value. If an intersection is found, this record is updated.