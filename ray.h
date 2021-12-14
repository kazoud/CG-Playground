//
//  ray.h
//  CG Playground
//
//  Created by Karim Dahrouge on 12/5/21.
//  Copyright © 2021 Karim Dahrouge. All rights reserved.
//

#ifndef ray_h
#define ray_h

#include "vec.h"

class ray{
    point3 origin;
    vec3 direction;
    
public:
    ray(point3 o, vec3 dir) : origin(o), direction(dir) {}
    
    vec3 at(double t)
    {
        return origin + direction*t;
    }
    
    point3 getOrigin() const
    {
        return origin;
    }
    
    vec3 getDirection() const
    {
        return direction;
    }
    
};

#endif /* ray_h */
