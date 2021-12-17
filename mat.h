//
//  mat.h
//  CG Playground
//
//  Created by Karim Dahrouge on 12/6/21.
//  Copyright © 2021 Karim Dahrouge. All rights reserved.
//

#ifndef mat_h
#define mat_h

#include "vec.h"

class mat4{
    double m[4][4] = {0};
    
public:
    mat4(double arr[16]) // Constructor
    {
        for (int i = 0; i < 16; i++)
        {
            int j = i/4;
            int k = i%4;
            
            m[j][k] = arr[i];
        }
    }
    
    double& operator ()(int i, int j) // Indexing with parentheses
    {
        return m[i][j];
    }
    
    mat4(const mat4& mat) // Copy constructor
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                m[i][j] = mat.m[i][j];
            }
        }
    }
    
    mat4 translate(vec4 t)
    {
        mat4 mat = *this;
        mat.m[0][3] += t.getX();
        mat.m[1][3] += t.getY();
        mat.m[2][3] += t.getZ();
        mat.m[3][3] += t.getW();
        
        return mat;
    }
    
    friend std::ostream& operator <<(std::ostream& out, const mat4& m);
    
};

std::ostream& operator <<(std::ostream& out, const mat4& mat)
{
    for (int i = 0; i < 4; i++)
    {
        out << '[' ;
        
        for (int j = 0; j < 4; j++)
        {
            out << mat.m[i][j] ;
            
            if (j == 3)
            {
                out << ']' << std::endl;
            }
            
            else
            {
                out << ',';
            }
        }
    }
    return out;
}

#endif /* mat_h */
