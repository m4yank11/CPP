#include <iostream>
using namespace std;
int main() {
    int size;
    cout<<"enter the size: "<<endl;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int max=INT_MIN;
    int smax= max;
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            
            smax=max;
            max=arr[i];
            }
    }
    cout<<smax<<endl;
    
    
}
