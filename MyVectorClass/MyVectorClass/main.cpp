//
//  main.cpp
//  MyVectorClass
//
//  Created by Sigursteinn Bjarni on 13/06/15.
//  Copyright (c) 2015 Sigursteinn Bjarni. All rights reserved.
//

#include <iostream>
#include "Vector3.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    float coords[3] = {1.0f, 2.0f, 3.0f};
    
    Vector3 u;
    Vector3 v = coords;
    Vector3 w(-5.0f, 2.0f, 0.0f);
    
    
    cout << "u vector = ";
    u.print();
    
    cout << "v vector = ";
    v.print();
    
    cout << "w vector = ";
    w.print();
    
    cout << "Add function: u = v + w ";
    u = v.add(w);
    u.print();
    
    cout << "Lenght: ||v|| = ";
    cout << v.lenght() << endl;
    
    cout << "Normalize: v = v/||v|| ";
    v.normalize();
    v.print();
    
    cout << "Dot product: u * v = ";
    float dotP = u.dot(v);
    cout << dotP << endl;
    
    cout << "Input your own vector" << endl;
    Vector3 myVector;
    myVector.input();
    cout << "Your vector is: ";
    myVector.print();
    
    return 0;
}
