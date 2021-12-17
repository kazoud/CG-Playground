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
    
     srand(time(0));
    
    double a[16];
    for (int i = 0; i < 16; i++)
    {
        a[i] = rand() % 100;
    }
    
    mat4 m(a);
    
    std::cout << m << std::endl;
    
    m(1,1) = m(1,1) + 3;
    
    std::cout << m << std::endl;
    return 0;
}
