#include <iostream>
#include <set>
using namespace std;

void printdivisors(int n){
    //store the divisors in a set
    set<int> s;
    for(int i = 1; i<=sqrt(n);i++){
        if(n%i==0){
            s.insert(i);
            s.insert(n/i);
        }
    }
    for(auto it:s){
        cout<<it<<" ";
    }
}

int main(){
    int n = 36;
    printdivisors(n);
    cout<<endl;
    return 0;
}
