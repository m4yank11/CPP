//
//  main.cpp
//  Maze path
//
//  Created by Mayank Raj Gupta on 20/04/24.
//

#include <iostream>
using namespace std;

//sr-> starting row
//sc-> starting column
//er-> ending row
//ec-> ending column

int mazePath(int sr,int sc,int er,int ec){
    //base case
    if(sr>er || sc>ec) return 0;
    if(sr==er && sc==ec) return 1;
    //if first traveled to right then starting col+1 and same with column
    int rightways = mazePath(sr, sc+1, er, ec);
    int downways = mazePath(sr+1, sc, er, ec);
    // total no. of ways is the sum of both the subpaths
    int totalways = rightways + downways;
    return totalways;
}
//using only two parameters
int mazePath2(int sr, int sc){
    if(sr<0 || sc<0) return 0;
    if(sr==0 && sc==0) return 1;
    int rightways = mazePath2(sr, sc-1);
    int downways = mazePath2(sr-1, sc);
    int totalways = rightways + downways;
    return totalways;
}

//printing the path
void printPath(int sr,int sc,int er,int ec, string s){
    if(sr>er || sc>ec) return;
    if(sr==er && sc==ec){//destination reached so print the path
        cout<<s<<endl;
        return;
    }
    printPath(sr, sc+1, er, ec,s+'R'); // we have travelled a row so path me R append ho jayega
    printPath(sr+1, sc, er, ec,s+'D');
    return;
}

//printing using only 2 parameters
void printPath2(int sr,int sc, string s){
    if(sr<0 || sc<0) return;
    if(sr==0 && sc==0){
        cout<<s<<endl;
        return;
    }
    printPath2(sr, sc-1, s+'R');
    printPath2(sr-1, sc, s+'D');
}

int main(){
    int sr,sc,er,ec;
//    cout<<"Enter starting row, staring column, ending row, ending column: ";
//    cin>>sr>>sc>>er>>ec;
//    cout<<"Total paths: "<<mazePath(sr,sc,er,ec)<<endl;
//    printPath(sr, sc, er, ec, "");
    
    cout<<"Total paths: "<<mazePath2(1,1)<<endl;
    printPath2(1, 1, "");
    return 0;
    
}
