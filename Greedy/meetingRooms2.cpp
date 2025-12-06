#include<iostream>
#include <vector>
#include <string>
using namespace std;
int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int result = 0;
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int rooms = 0;
        int i = 0 , j = 0;
        while(i < start.size()){
            if(start[i] < end[j]){
                rooms++;
                result = max(result, rooms);
                i++;
            }
            else{
                rooms--;
                j++;
            }
        }
        return result;
    }
int main(){
    return 0;
}