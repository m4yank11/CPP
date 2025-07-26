//
//  main.cpp
//  Pre In Post
//
//  Created by Mayank Raj Gupta on 23/04/24.
//

#include <iostream>
using namespace std;

void pip(int n){
    if(n==0) return;
    cout<<"Pre "<<n<<endl;
    pip(n-1);
    cout<<"In "<<n<<endl;
    pip(n-1);
    cout<<"Post "<<n<<endl;
}
int main(){
    int n = 3;
    pip(n);
}
