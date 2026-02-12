#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

string minWindow(string s, string t) {
    vector<int> need(128, 0);

    for(char c : t)
        need[c]++;

    int left = 0, right = 0;
    int required = t.length();
    int minLen = INT_MAX;
    int start = 0;

    while(right < s.length()) {
        if(need[s[right]] > 0)
            required--;

        need[s[right]]--;
        right++;

        while(required == 0) {
            if(right - left < minLen) {
                minLen = right - left;
                start = left;
            }

            need[s[left]]++;
            if(need[s[left]] > 0)
                required++;

            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main(){
    

// s = "ADOBECODEBANC", t = "ABC"
    string a = minWindow("ADOBECODEBANC", "ABC");
    cout<<a<<endl;   
    return 0;
}