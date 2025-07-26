//
//  main.cpp
//  Tower of Hanoi
//
//  Created by Mayank Raj Gupta on 10/07/24.
//

#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c){
    if(n==0) return;
    //n-1 disks from a to b using c
    hanoi(n-1,a,c,b);
    //biggest disk to c
    cout<<a<<" -> "<<c<<endl;
    //n-1 disks from b to c using a
    hanoi(n-1, b, a, c);
}

int main() {
    //we will pass 4 parameters to the function
    // the number of disks
    // starting tower, helping tower and destination tower
    int n;
    cin>>n;
    hanoi(n,'A','B','C');
    return 0;
}
