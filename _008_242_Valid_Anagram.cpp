#include <iostream>
#include <string>
using namespace std;

// 97-122  -  a-z
bool isAnagram(string s, string t) {
    int count[26] = {0};

    for(char c : s){
        count[int(c) - 97]++;
    }
    for(char c : t){
        count[int(c) - 97]--;
    }

    for(int i : count){
        if(i != 0){
            return false;
        }
    }

    return true;
}

int main(){
    string s = "rat";
    string t = "car";
    cout<<isAnagram(s,t);
    
    return 0;
}