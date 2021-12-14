//
//  main.cpp
//  CG Playground
//
//  Created by Karim Dahrouge on 12/1/21.
//  Copyright © 2021 Karim Dahrouge. All rights reserved.
//

#include <iostream>
#include "ray.h"
#include "sphere.h"
#include "plane.h"

int main() {
    
    vec3 x(2,0,0);
    vec3 y(0,3,0);
    
    std::cout << cross(x, y) << std::endl;
    
    return 0;
}
