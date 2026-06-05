#include <iostream>
using namespace std;

int main(){
    
    return 0;
}

string defangIPaddr(string address) {
    string ans = "";
    for(char c : address){
        if(c == '.'){
            ans += "[.]";
        }
        else{
            ans += c;
        }
    }
    return ans;
}