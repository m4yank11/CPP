#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minProductSubset(vector<int>& arr){
    int cz = 0, cn = 0 , cp = 0;
    int largestNeg = 0;
    int negProd = 1, posProd = 1;

    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i] < 0){
            cn ++;
            largestNeg = max(largestNeg, arr[i]);
            negProd *= arr[i];
        }
        else if(arr[i] == 0) cz++;
        else{
            cp++;
            posProd *= arr[i];
        }

    }

    if(cn == 0){
        if(cz == 0){
            return *min_element(arr.begin(), arr.end());
        } else return 0;
    }
    else if(cn > 0){
        if(cn % 2 == 0){
            //even number of negatives
            return (negProd/largestNeg)*posProd;
        }
        // else{
        //     //odd number of negatives
        //     return negProd * posProd;
        // }
    }
    return negProd * posProd;
}

int main(){
    vector<int>arr = {11, 3, -1,-5};
    cout<<minProductSubset(arr)<<endl;

}