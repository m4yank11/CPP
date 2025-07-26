#include<iostream>
#include <vector>
#include <string>
using namespace std;

void generate(string s, int n){
    if(s.length()==n){
        cout<<s<<endl;
        return;
    }
    if(s[s.length()-1]!='1'){
        generate(s+"1",n);
    }
    generate(s+'0',n);

}

int main(){
    int n = 4;
    generate("",n);
}