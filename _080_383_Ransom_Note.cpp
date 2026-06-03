#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}

bool canConstruct(string ransomNote, string magazine) {
    vector<int> counts(26, 0);

    for(char c : magazine){
        counts[c-'a']++;
    }

    for(char c : ransomNote){
        counts[c-'a']--;

        if(counts[c-'a'] < 0){
            return false;
        }
    }

    return true;
}