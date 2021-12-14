//
//  box.h
//  CG Playground
//
//  Created by Karim Dahrouge on 12/15/21.
//  Copyright © 2021 Karim Dahrouge. All rights reserved.
//

#ifndef box_h
#define box_h
#include "ray.h"

class box3{
    vec3 lower_bound, higher_bound;
    
public:
    box3(vec3 l, vec3 h) : lower_bound(l), higher_bound(h) {}
};

void intersect(const vec3& v, const box3& b, hit_record& rec)
{
    
}

#endif /* box_h */
