//
//  polymorphismExample.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/30/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include<iostream>

using namespace std;

// This is a true problem I met in an interview.

// What is the output of the following program?
// Answer: Base

class Base {
public:
    void f() {
        cout<<"Base\n";
    }
};

class Derived:public Base {
public:
    void f() {
        cout<<"Derived\n";
    }
};

int main() {
    Base *p = new Derived();
    
    p->f();
}
