//
//  Vector3.cpp
//  MyVectorClass
//
//  Created by Sigursteinn Bjarni on 13/06/15.
//  Copyright (c) 2015 Sigursteinn Bjarni. All rights reserved.
//

#include "Vector3.h"
#include "math.h"
#include <iostream>

using namespace std;

// Constructors

Vector3::Vector3(){
    m_X = m_Y = m_Z = 0;
}

Vector3::Vector3(float coords[3]){
    
    m_X = coords[0];
    m_Y = coords[1];
    m_Z = coords[2];
}

Vector3::Vector3(float x, float y, float z){

    m_X = x;
    m_Y = y;
    m_Z = z;
    
}

// Check if two vectors are equal

bool Vector3::equals(const Vector3 &rhs){
    
    return m_X == rhs.m_X && m_Y == rhs.m_Y && m_Z == rhs.m_Z;
}

// Add two vectors together and return the new vector

Vector3 Vector3::add(const Vector3 &rhs){
    
    Vector3 sumVector;
    
    sumVector.m_X = m_X + rhs.m_X;
    sumVector.m_Y = m_Y + rhs.m_Y;
    sumVector.m_Z = m_Z + rhs.m_Z;
    
    return sumVector;
}

// subtract two vectors and return the new vector

Vector3 Vector3::sub(const Vector3 &rhs){

    Vector3 subVector;
    
    subVector.m_X = m_X - rhs.m_X;
    subVector.m_Y = m_Y - rhs.m_Y;
    subVector.m_Z = m_Z - rhs.m_Z;
    
    return subVector;
}

// Scalar Multiplication

Vector3 Vector3::mul(float scalar){

    Vector3 mulVector;
    
    mulVector.m_X = m_X * scalar;
    mulVector.m_Y = m_Y * scalar;
    mulVector.m_Z = m_Z * scalar;
    
    return mulVector;
}

// returns the magnitude of the vector

float Vector3::lenght(){

    return sqrtf((m_X * m_X) + (m_Y * m_Y) + (m_Z * m_Z));
}

// Normalized a Vector
void Vector3::normalize(){
    
    float len = lenght();
    
    m_X /= len;
    m_Y /= len;
    m_Z /= len;
}

float Vector3::dot(const Vector3 &rhs){
    
    float dot = (m_X * rhs.m_X) + (m_Y * rhs.m_Y) + (m_Z * rhs.m_Z);
    
    return dot;

}

void Vector3::print(){
    cout << "< " << m_X <<", " << m_Y <<", " << m_Z << " >" << endl;
}

void Vector3::input(){

    cout << "Enter in x: ";
    cin >> m_X;
    cout << "Enter in y: ";
    cin >> m_Y;
    cout << "Enter in z: ";
    cin >> m_Z;
}

// Overloading operators

Vector3 Vector3::operator+(const Vector3 &rhs){
    
    Vector3 sumVector;
    
    sumVector.m_X = m_X + rhs.m_X;
    sumVector.m_Y = m_Y + rhs.m_Y;
    sumVector.m_Z = m_Z + rhs.m_Z;
    
    return sumVector;
}

Vector3 Vector3::operator-(const Vector3 &rhs){
    
    
    Vector3 subVector;
    
    subVector.m_X = m_X - rhs.m_X;
    subVector.m_Y = m_Y - rhs.m_Y;
    subVector.m_Z = m_Z - rhs.m_Z;
    
    return subVector;
}

Vector3 Vector3::operator*(float scalar){

    Vector3 mulVector;
    
    mulVector.m_X = m_X * scalar;
    mulVector.m_Y = m_Y * scalar;
    mulVector.m_Z = m_Z * scalar;
    
    return mulVector;

}

float Vector3::operator*(Vector3 &rhs){
    return this->dot(rhs);
    
}


// Overloaded relational operators

bool Vector3::operator== (const Vector3 &rhs){

    return m_X == rhs.m_X && m_Y == rhs.m_Y && m_Z == rhs.m_Z;
}

bool Vector3::operator!=(const Vector3 &rhs){
    
    return m_X != rhs.m_X || m_Y != rhs.m_Y || m_Z != rhs.m_Z;
}

