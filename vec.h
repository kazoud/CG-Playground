//
//  vec.h
//  CG Playground
//
//  Created by Karim Dahrouge on 12/1/21.
//  Copyright © 2021 Karim Dahrouge. All rights reserved.
//

#ifndef vec_h
#define vec_h

#include "math.h"

class vec2 {
    double x, y;
    
public:
    vec2(double a, double b) : x(a), y(b) {}
    vec2() : x(0), y(0) {}
    
    double getX() const
    {
        return x;
    }
    
    double getY() const
    {
        return y;
    }
    
    void setX(double a)
    {
        x = a;
    }
    
    void setY(double b)
    {
        y = b;
    }
    
    double length() // Traditionally defined as sqrt(dot(vec,vec))
    {
        return sqrt(x*x + y*y);
    }
    
    vec2 operator *(int a)
    {
        return vec2(a*x, a*y);
    }
    
    vec2 operator /(int a)
    {
        return (*this) * (1/a);
    }
    
    vec2 operator +(vec2 a)
    {
        return vec2(x + a.x, y + a.y);
    }
    
    vec2 operator -(vec2 a)
    {
        return vec2(x - a.x, y - a.y);
    }
};

double dot(vec2 a, vec2 b)
{
    return a.getX() * b.getX() + a.getY() * b.getY();
}

double angle(vec2 a, vec2 b)
{
    double cos = dot(a,b) / ( a.length() * b.length() );
    return acos(cos) * 180.0 /3.14159265;
}

class vec3 {
    double x, y, z;
    
public:
    vec3(double a, double b, double c) : x(a), y(b), z(c) {}
    vec3() : x(0), y(0), z(0) {}
    
    double getX() const
    {
        return x;
    }
    
    double getY() const
    {
        return y;
    }
    
    double getZ() const
    {
        return z;
    }
    
    void setX( double a)
    {
        x = a;
    }
    
    void setY(double b)
    {
        y = b;
    }
    
    void setZ(double c)
    {
        z = c;
    }
    
    double length() const
    {
        return sqrt(x*x + y*y + z*z);
    }
    
    vec3 operator+(vec3 v)
    {
        return vec3(x+v.x, y+v.y, z+v.z);
    }
    
    vec3 operator-(vec3 v)
    {
        return vec3(x-v.x, y-v.y, z-v.z);
    }
    
    vec3 operator*(double a)
    {
        return vec3(a*x, a*y, a*z);
    }
    
    friend std::ostream& operator<<(std::ostream& out, vec3 vec) ;
    
};

std::ostream& operator <<(std::ostream& out, vec3 vec)
{
    out << "[" << vec.getX() << ", " << vec.getY() << ", " << vec.getZ() << ']';
    return out;
}

double dot(const vec3& v1, const vec3& v2)
{
    return v1.getX()*v2.getX() + v1.getY()*v2.getY() + v1.getZ()*v2.getZ();
}

vec3 cross(const vec3& v1, const vec3& v2)
{
    double x = v1.getY()*v2.getZ() - v1.getZ()*v2.getY();
    double y = v1.getZ()*v2.getX() - v1.getX()*v2.getZ();
    double z = v1.getX()*v2.getY() - v1.getY()*v2.getX();
    
    return vec3(x,y,z);
}

double angle(const vec3& a, const vec3& b)
{
    double cos = dot(a,b) / ( a.length() * b.length() );
    return acos(cos) * 180.0 /3.14159265;
}

using point3 = vec3;

class vec4{
    double x,y,z,w;
    
public:
    vec4(double a, double b, double c, double d) : x(a), y(b), z(c), w(d) {}
    
};

struct hit_record{
    bool hit;
    double t1, t2;
    
    friend std::ostream& operator <<(std::ostream& out, const hit_record& rec);
};

std::ostream& operator <<(std::ostream& out, const hit_record& rec)
{
    std::string message = rec.hit == true ? "There is an intersection" : "There is no intersection";
    out << message << std::endl;
    
    if (rec.hit)
    {
        out << "t1:" << rec.t1 << std::endl << "t2:" << rec.t2;
    }
    return out;
}

#endif /* vec_h */
