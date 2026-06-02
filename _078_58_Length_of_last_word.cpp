#include <iostream>
using namespace std;

int main(){
    
    return 0;
}

int lengthOfLastWord(string s) {
    int len = 0;
    bool flag = false;

    int n = s.length();

    for(int i = n-1; i>=0; i--){
        if(s[i] != ' '){
            flag = true;
        }

        if(flag){
            if(s[i] == ' '){
                flag = false;
                break;
            }
            len++;
        }
    }
    return len;
}