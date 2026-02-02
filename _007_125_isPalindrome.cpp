#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// brute force
bool isPalindrome_1(string s) {
    string ans;
    for(char c : s){
        c = tolower((unsigned char)c);
        if(isalnum((unsigned char)c)){
            ans += c;
        }
    }

    bool res = true;
    for(int i = 0; i < ans.length()/2; i++){
        if(ans[i] != ans[ans.length() - 1 - i]){
            res = false;
            break;
        }
    }

    return res;
}

// Efficient code
bool isPalindrome_best(string s) {
    int l = 0, r = s.length() - 1;

    while(l < r) {
        while(l < r && !isalnum((unsigned char)s[l])) l++;
        while(l < r && !isalnum((unsigned char)s[r])) r--;

        if(tolower((unsigned char)s[l]) != tolower((unsigned char)s[r]))
            return false;

        l++;
        r--;
    }
    return true;
}



int main(){
    cout<<isPalindrome_1("A man, a plan, a canal: Panama")<<endl;
    cout<<isPalindrome_best("A man, a plan, a canal: Panama")<<endl;

    return 0;
}