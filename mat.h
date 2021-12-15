//
//  mat.h
//  CG Playground
//
//  Created by Karim Dahrouge on 12/6/21.
//  Copyright © 2021 Karim Dahrouge. All rights reserved.
//

#ifndef mat_h
#define mat_h

class mat4{
    double m[16] = {0};
    
public:
    mat4(double arr[16])
    {
        for (int i = 0; i < 16; i++)
        {
            m[i] = arr[i];
        }
    }
    
    double& operator ()(int i, int j) //Not finished
    {
        return m[4*i + j];
    }
    
    mat4(const mat4& mat)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                m[i] = mat.m[i];
            }
        }
    }
    
    friend std::ostream& operator <<(std::ostream& out, const mat4& m);
    
};

std::ostream& operator <<(std::ostream& out, const mat4& mat)
{
    
    for (int i = 0; i < 16; i++)
    {
        if (i%4 == 0)
        {
            out << std::endl << '[';
        }
        
        out << mat.m[i];
        
        if (i%4 != 3)
        {
            out << ",";
        }
        
        if (i%4 == 3)
        {
            out << ']';
        }
    }
    out << std::endl;
    return out;
}

#endif /* mat_h */
