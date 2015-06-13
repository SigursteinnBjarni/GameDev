//
//  Vector3.h
//  MyVectorClass
//
//  Created by Sigursteinn Bjarni on 13/06/15.
//  Copyright (c) 2015 Sigursteinn Bjarni. All rights reserved.
//

#ifndef __MyVectorClass__Vector3__
#define __MyVectorClass__Vector3__

#include <stdio.h>

class Vector3{

public:
    Vector3();
    Vector3(float coords[3]);
    Vector3(float x, float y, float z);
    
    bool equals (const Vector3 &rhs);
    Vector3 add (const Vector3 &rhs);
    Vector3 sub (const Vector3 &rhs);
    Vector3 mul (float scalar);
    float lenght();
    void normalize();
    float dot(const Vector3 &rhs);
    
    
    void print();
    void input();
    
    float m_X, m_Y, m_Z;
    
    // Overloading operators, you can use these instad of the functions
    
    Vector3 operator+ (const Vector3 &rhs);
    Vector3 operator- (const Vector3 &rhs);
    Vector3 operator* (float scalar);
    float operator* (Vector3 &rhs);
    
    // Overloading relational operators
    
    bool operator== (const Vector3 &rhs);
    bool operator!= (const Vector3 &rhs);
    

    
};



#endif /* defined(__MyVectorClass__Vector3__) */
