//
//  main.cpp
//  seive algo leetcode 3233
//
//  Created by Mayank Raj Gupta on 01/08/24.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 100001;
    vector <bool> primes(n,true);
    primes[0]=0;
    primes[1] = 0;
    for(int i=2;i<n;i++){
        if(primes[i]==false)break;
        for(int j=i*2;j<n;j+=i){
            primes[j] = false;
        }
    }
    
    for(int i=1;i<=10;i++){
        if(primes[i]){
            cout<<i<<' ';
        }
    }
    
    cout<<endl;
}
