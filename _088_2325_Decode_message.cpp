#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    
    return 0;
}

string decodeMessage(string key, string message) {
    unordered_map<char, int> mp;

    int i = 0;
    for(char c : key){
        if(c != ' '&& mp.find(c) == mp.end()){
            mp.insert({c,i++});
        }
    }

    string ans = "";

    for(char c : message){
        if(c == ' ') {
            ans += ' ';
        } else {
            ans += mp[c]+'a';
        }
    }   
    return ans;
}