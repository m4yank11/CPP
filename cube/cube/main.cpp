//
//  main.cpp
//  cube
//
//  Created by Mayank Raj Gupta on 08/08/23.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    for(int i=1;i<=num;i++){
        cout<<setw(4)<<i;
        int cube=i*i*i;
        cout<<setw(6)<< cube <<endl;
        
    }
    return 0;
}
