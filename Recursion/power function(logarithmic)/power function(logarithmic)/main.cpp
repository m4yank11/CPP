//
//  main.cpp
//  power function(logarithmic)
//
//  Created by Mayank Raj Gupta on 20/04/24.
//

#include <iostream>
using namespace std;

int power(int x,int n){
    if(n==0) return 1;
    if(n==1) return x;
    int ans = power(x,n/2);
    if(n%2==0){
        return ans*ans;
    }
    else return ans*ans*x;
}

int main(){
    cout<<power(2, 0)<<endl;
}
