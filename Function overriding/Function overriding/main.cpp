//
//  main.cpp
//  Function overriding
//
//  Created by Mayank Raj Gupta on 14/09/23.
//

#include <iostream>
using namespace std;

class base{
public:
    int a,b;
    virtual void print(int a,int b){
        cout<<"Sum: "<<a+b<<endl;
    }
};

class derived: public base{
public:
    //function overriding
    void print(int a,int b){
        cout<<"Difference: "<<a-b<<endl;
        
    }
    void display(int a,int b){
        cout<<"Multiplication: "<<a*b<<endl;
    }
};

int main(){
    base obj;
    derived ob;
    int a,b;
    cout<<"Enter the numbers: ";
    cin>>a>>b;
    base* bp;
    derived* dptr=& ob; //derived class pointer to derived class object
    bp= &obj; //base class pointer to base class object
    bp->print(a, b);
    bp= &ob;
    bp->print(a, b);
    dptr->print(a, b);
    dptr->display(a, b);
    cout<<sizeof(bp)<<endl;
    
    return 0;
}
