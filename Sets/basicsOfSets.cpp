#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    for(int i: s){
        cout<<i<<" ";
    }
    cout<<endl;
    s.erase(3);
    for(int i: s){
        cout<<i<<" ";
    }
    cout<<endl;
    int target = 3;
    if(s.find(target)!=s.end()){
        // target exists
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    
}