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
    
    mat4(double arr[4][4]) // Constructor #2
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
               m[i][j] = arr[i][j];
            }
        }
    }
    
    mat4(vec4 col1, vec4 col2, vec4 col3, vec4 col4) // Constructor #3 (Terrible)
    {
        m[0][0] = col1.getX();
        m[1][0] = col1.getY();
        m[2][0] = col1.getZ();
        m[3][0] = col1.getW();
        m[0][1] = col2.getX();
        m[1][1] = col2.getY();
        m[2][1] = col2.getZ();
        m[3][1] = col2.getW();
        m[0][2] = col3.getX();
        m[1][2] = col3.getY();
        m[2][2] = col3.getZ();
        m[3][2] = col3.getW();
        m[0][3] = col4.getX();
        m[1][3] = col4.getY();
        m[2][3] = col4.getZ();
        m[3][3] = col4.getW();
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
    
    double& operator ()(int i, int j) // Indexing with parentheses
    {
        return m[i][j];
    }
    
    
    mat4 scale(const vec3& s)
    {
        mat4 mat = *this;
        mat.m[0][0] *= s.getX();
        mat.m[1][1] *= s.getY();
        mat.m[2][2] *= s.getZ();
    
        return mat;
    }
    
    mat4 translate(const vec3& t)
    {
        mat4 mat = *this;
        mat.m[0][3] += t.getX();
        mat.m[1][3] += t.getY();
        mat.m[2][3] += t.getZ();
        
        return mat;
    }
    
    mat4 operator*(mat4& mat) ;
    
    friend std::ostream& operator <<(std::ostream& out, const mat4& m);
    
};

mat4 identity()
{
    double identity[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    return mat4(identity);
}

mat4 zeroes()
{
    double zeroes[4][4] = {0};
    return mat4(zeroes);
}

mat4 transfact(mat4& m)
{
    mat4 trans = identity();
    
    for (int i = 0; i < 3; i++)
    {
        trans(i,3) = m(i,3);
    }
    
    return trans;
}

mat4 linfact(mat4& m)
{
    mat4 lin = zeroes();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            lin(i,j) = m(i,j);
        }
    }
    lin(3,3) = 1;
    return lin;
}

mat4 lookat(point3 eye, point3 direction, vec3 up)
{
    vec3 z = (direction-eye).normalize();
    vec4 augmented_z(z, 0);
    vec3 y = up.normalize();
    vec4 augmented_y(y, 0);
    vec3 x = cross(y,z);
    vec4 augmented_x(x,0);
    vec4 p(eye, 1);
    
    return mat4(augmented_x,augmented_y,augmented_z,p);
}

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

mat4 mat4::operator*(mat4& mat)
{
    mat4 product = zeroes();
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                product(i,j) += (*this)(i,k) * mat(k,j);
            }
        }
    }
    return product;
    
}

#endif /* mat_h */
