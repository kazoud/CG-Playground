//
//  sphere.h
//  CG Playground
//
//  Created by Karim Dahrouge on 12/5/21.
//  Copyright © 2021 Karim Dahrouge. All rights reserved.
//

#ifndef sphere_h
#define sphere_h

#include "ray.h"


class sphere {
    point3 center;
    double radius;
    
public:
    sphere(point3 c, double r) : center(c), radius(r) {}
    
    point3 getCenter() const
    {
        return center;
    }
    
    double getRadius() const
    {
        return radius;
    }
};

void intersect(const ray& r, const sphere& s, hit_record& rec)
{
    vec3 ray_dir = r.getDirection();
    point3 ray_orig = r.getOrigin();
    
    point3 sphere_center = s.getCenter();
    double radius = s.getRadius();
    
    double a = dot(ray_dir, ray_dir);
    double b = 2*dot(ray_orig - sphere_center, ray_dir);
    double c = dot(ray_orig - sphere_center,ray_orig - sphere_center) - radius*radius;
    
    double discriminant = b*b - 4*a*c;
    
    if(discriminant < 0)
    {
        rec.hit = false;
    }
    else
    {
        rec.hit = true;
        rec.t1 = (-b + sqrt(discriminant)) / 2*a ;
        rec.t2 = (-b - sqrt(discriminant)) / 2*a ;
    }
}

#endif /* sphere_h */
