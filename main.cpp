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
#include "mat.h"

int main() {
    
    mat4 m = identity();
    
    vec3 scalor(2.0, 2.0, 2.0);
    vec3 translator(1.0,2.0,3.0);
    
    m = m.scale(scalor);
    m = m.translate(translator);
    
    mat4 trans = transfact(m);
    mat4 lin = linfact(m);
    
    std::cout << m << std::endl;
    std::cout << trans << std::endl;
    std::cout << lin << std::endl;
    
    return 0;
}
