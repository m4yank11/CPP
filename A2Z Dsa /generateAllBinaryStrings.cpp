#include<iostream>
using namespace std;
// we are given an integer 'n' we have to count and generate all strings of length n where there are no consecutive 1's

void generate(string s, int n, int k, int& count){
    if(n == k){
        cout<<s<<endl;
        count++;
        return;
    }
    if(s.back() == '0'){
        generate(s + '0', n, k + 1, count);
        generate(s + '1', n, k + 1, count);
    }
    else{
        generate(s + '0', n, k + 1, count);
    }    
}


int countstrings(int n){
    if(n <= 0) return 0;
    int count = 0;
    string s = "";
    s.push_back('0');
    generate(s, n, 1, count);
    s.pop_back();
    s.push_back('1');
    generate(s, n, 1, count);
    return count;

}

int main(){
    int n;
    cin >> n;
    cout<<countstrings(n)<<endl;
    return 0;

}