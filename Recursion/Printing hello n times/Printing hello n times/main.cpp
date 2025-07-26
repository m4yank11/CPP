//
//  main.cpp
//  Printing hello n times
//
//  Created by Mayank Raj Gupta on 18/04/24.
//

#include <iostream>
using namespace std;

void print(int x){
    if(x==0) return;
    cout<<"hello"<<endl;
    print(x-1);
}

int main(int argc, const char * argv[]) {
    int x;
    cin>>x;
    print(x);
    return 0;
}
