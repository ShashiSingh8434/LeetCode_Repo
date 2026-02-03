#include <iostream>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    int count[26] = {0};
    int index = 0;

    for(char c : s){
        count[int(c) - 97]++;
    }
    for(char c : s){
        if(count[int(c) - 97] == 1){
            return index;
        }
        index++;
    }

    return -1;
}

int main(){
    cout<<firstUniqChar("leetcode");
    return 0;
}