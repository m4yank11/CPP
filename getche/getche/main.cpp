//
//  main.cpp
//  getche
//
//  Created by Mayank Raj Gupta on 18/08/23.
//
// chcount.cpp
// counts characters and words typed in
#include <iostream>
using namespace std;
#include <conio.h>
int main() {
   int chcount=0;
   int wdcount=1;
   char ch = ‘a’;
   cout << “Enter a phrase: “;
   while( ch != ‘\r’ )
//counts non-space characters
//counts spaces between words
//ensure it isn’t ‘\r’
//loop until Enter typed
{
ch = getche();
if( ch==’ ‘ )
wdcount++;
else
chcount++;
}
//read one character
//if it’s a space
//count a word
//otherwise,
//count a character
                           //display results
cout << “\nWords=” << wdcount << endl
//for getche()
        << “Letters=” << (chcount-1) << endl;
   return 0;
}
