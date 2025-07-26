//
//  main.cpp
//  Functions
//
//  Created by Mayank Raj Gupta on 16/09/23.
//

#include <iostream>
using namespace std;

void display(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            cout<<"x";
        }
        cout<<endl;
    }
    
}
int main(){
    int n;
    display(3);
    return 0;
}
