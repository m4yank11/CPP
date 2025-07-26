//
//  main.cpp
//  print substrings of a string(with duplicates)
//
//  Created by Mayank Raj Gupta on 28/07/24.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//algorithm:
//we will make two recursive calls, first call me first character append krenge
//aur second me nhi krenge
//lekin isse hume duplicate substrings milenge. usko avoid krne ke liye hum ek flag bhi pass krenge jo pehle true hoga, agar flag false hota hai to hum second recursive call nhi krenge

void printDupSub(string ans,string original,vector<string>&v, bool flag){
    sort(original.begin(),original.end());
    if(original == ""){ //base case
        v.push_back(ans);
        return;
    }
    char ch = original[0];
    if(original.length()==1){
        if(flag==true) printDupSub(ans+ch, original.substr(1), v, true);
        printDupSub(ans,original.substr(1), v, true);
        return;
        //return statement isliye daali hai taaki neeche ki conditions run na kre
        
    }
    char dh = original[1];
    if(ch==dh){
        //duplicate
        if(flag==true) printDupSub(ans+ch, original.substr(1), v, true);
        printDupSub(ans, original.substr(1), v, false);
    }
    else {
        if(flag==true) printDupSub(ans+ch, original.substr(1), v, true);
        printDupSub(ans, original.substr(1), v, true);
    }
}

int main() {
    string s = "122";
    vector<string> ans;
    string f = "";
    printDupSub(f, s, ans, true);
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
