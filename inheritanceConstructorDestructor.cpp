//
//  inheritanceConstructorDestructor.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/30/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

// What is the output of the following program?
// Answer:
// create B
// create A
// create C
// destruct C
// destruct A
// destruct B

#include <iostream>
using namespace std;

class A{
public:
    A(){cout<<"create A"<<endl;}
    ~A(){cout<<"destruct A"<<endl;}
};
class B{
public:
    B(){cout<<"create B"<<endl;}
    ~B(){cout<<"destruct B"<<endl;}
};

class C:public B{
public:
    A a;
    C(){cout<<"creat C"<<endl;}
    ~C(){cout<<"destruct C"<<endl;}
};

int main(){
    C c;
    return 1;
}
