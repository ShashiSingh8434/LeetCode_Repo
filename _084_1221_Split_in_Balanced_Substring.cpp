#include <iostream>
using namespace std;

int main(){
    
    return 0;
}

int balancedStringSplit(string s) {
    int ans = 0;
    int count = 0;
    char flag = s[0];

    for(char c : s){
        if(c == flag){
            count++;
        }
        else{
            count--;
        }

        if(count == 0){
            ans++;
        }
    }
    return ans;
}