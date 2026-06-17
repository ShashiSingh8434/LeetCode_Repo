#include <iostream>
using namespace std;

int main(){
    
    return 0;
}

string reverseWords(string s) {
    string ans = "";
    int n = s.length();
    int i = n - 1;

    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        if (i < 0) break;

        int j = i;
        while (i >= 0 && s[i] != ' ') {
            i--;
        }
        
        string temp = s.substr(i + 1, j - i);
        if (ans.empty()) {
            ans = temp;
        } else {
            ans += " " + temp;
        }
    }

    return ans;
}