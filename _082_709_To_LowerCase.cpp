#include <iostream>
using namespace std;

int main(){
    
    return 0;
}

string toLowerCase(string s) {
    string ans = "";
    for(char c : s){
        if(c >= 65 && c <= 90){
            int x = c - 'A';
            c = 'a' + x;
        }
        ans += c;
        
    }
    return ans;
}