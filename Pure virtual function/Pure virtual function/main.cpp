//
//  main.cpp
//  Pure virtual function
//
//  Created by Mayank Raj Gupta on 30/09/23.
//

#include <iostream>
using namespace std;

class area{
protected:
    double dim1,dim2;
public:
    void setarea(double d1, double d2){
        dim1 = d1;
        dim2 = d2;
    }
    virtual double getarea()=0;
    //must be overridden
    //this is a pure virtual function
};

class rectangle: public area{
    
public:
    double getarea(){
        return dim1*dim2;
    }
};

class triangle: public area{
    
public:
    double getarea(){
        return 0.5*dim1*dim2;
    }
};

int main(){
    area* p;
    rectangle r;
    triangle t;
    r.setarea(3.3, 4.5);
    t.setarea(3.3, 4.5);
    p= &r;
    cout<<p->getarea()<<endl;
    p= &t;
    cout<<p->getarea()<<endl;
}

