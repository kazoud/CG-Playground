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
    double m[4][4] = {0};
    
public:
    mat4(double arr[16])
    {
        for (int i = 0; i < 16; i++)
        {
            int j = i/4;
            int k = i%4;
            m[j][k] = arr[i];
        }
    }
    
    mat4(const mat4& mat)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                m[i][j] = mat[i][j];
            }
        }
    }
    
    double& operator ()(int i, int j) //Not finished
    {
        return m[i][j];
    }
    
};

#endif /* mat_h */
