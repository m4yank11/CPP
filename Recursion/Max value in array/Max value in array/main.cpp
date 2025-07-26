//
//  main.cpp
//  Max value in array
//
//  Created by Mayank Raj Gupta on 11/07/24.
//

#include <iostream>
#include <vector>
using namespace std;
void printMax(vector<int>& v,int idx, int max){
    if(idx==v.size()){ //base case
        cout<<max<<endl;
        return;
    }
    if(v[idx]>max) max = v[idx];
    printMax(v,idx+1,max);
}

int main(){
    //int arr[] = {2,4,1,6,3,1,7,9};
    vector<int> v = {2,4,1,6,3,1,7,9};
    printMax(v,0, INT_MIN);
    return 0;
}
