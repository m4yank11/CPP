//
//  main.cpp
//  constructoe
//
//  Created by Mayank Raj Gupta on 10/08/23.
//

#include <iostream>
using namespace std;

class student{
    string branch;
    string name;
    float cgpa;
    string id;
    
public:
    student(){
        cout<<"Enter the branch: ";
        cin>>branch;
        cout<<endl;
        cout<<"Enter the name: ";
        cin>>name;
        cout<<endl;
        cout<<"Enter cgpa: ";
        cin>>cgpa;
        cout<<endl;
        cout<<"Enter id: ";
        cin>>id;
    }
    
    void display(){
        cout<<endl<<branch<<endl<<name<<endl<<cgpa<<endl<<id<<endl;
    }
    
};

int main(){
    student s1;//constructor gets called automatically when we create the object of the class
    s1.display();
    return 0;
}
