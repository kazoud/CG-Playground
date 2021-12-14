//
//  plane.h
//  CG Playground
//
//  Created by Karim Dahrouge on 12/5/21.
//  Copyright © 2021 Karim Dahrouge. All rights reserved.
//

#ifndef plane_h
#define plane_h

#include "ray.h"

class plane {
    point3 p0;
    vec3 n;
    
public:
    plane(point3 p, vec3 normal) : p0(p), n(normal) {}
    
    vec3 getNormal() const
    {
        return n;
    }
    vec3 getP0() const
    {
        return p0;
    }
};

void intersect(const ray& r, const plane& p, hit_record& rec)
{
    double denom = dot(r.getDirection(), p.getNormal());
    if (abs(denom) > 1e-6)
    {
        rec.hit = true;
        rec.t1 = dot(p.getP0() - r.getOrigin(), p.getNormal()) / denom;
    }
    else
    {
        rec.hit = false;
    }
}

#endif /* plane_h */
