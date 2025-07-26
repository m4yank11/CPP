#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int main(){
    unordered_set<string> s;
    int count = 0;
    vector<string> words = {"cd","ac","dc","ca","zz"};
    for(int i = 0; i<words.size(); i++){
        string word = words[i];
        string rev= word;
        reverse(rev.begin(), rev.end());
        if(s.find(rev) != s.end()){
            count++;
            s.erase(rev);
        }
        else s.insert(word);
    }
    cout<<count<<endl;
}