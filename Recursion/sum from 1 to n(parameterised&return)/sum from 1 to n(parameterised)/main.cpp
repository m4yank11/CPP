//
//  main.cpp
//  sum from 1 to n(parameterised)
//
//  Created by Mayank Raj Gupta on 18/04/24.
//

#include <iostream>
using namespace std;

//parameterised
void sum1(int ans, int n){
    if(n==0) {
        cout<<ans<<endl;
        return;
    }
    sum1(ans+n,n-1);
}

//return
int sum2(int n){
    if(n==0) return 0;
    return n+sum2(n-1);
}

int main(){
    sum1(0,10);
    cout<<sum2(10)<<endl;
    return 0;
}
