#include <iostream>
#include <string>
#include <unordered_map>
#include <iterator>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int left = 0;
    int maxLength = 0;

    for (int i = 0; i < s.length(); i++){
        char c = s[i];

        if(map.count(c) && map[c] >= left){
            left = map[c] + 1;
        }

        map[c] = i;        
        maxLength = max(maxLength, i - left + 1);
    }
    return maxLength;
   
}
// int lengthOfLongestSubstring(string s) {
//     unordered_map<char, int> map;
//     int n = s.length();
//     int i = 0;

//     int maxLength = 0;

//     while (i < n){
//         if(map.find(s[i]) != map.end()){
//             int pos = distance(map.begin(), map.find(s[i]));

//             for (int i = 0; i <= pos; i++){
//                 map.erase(0);
//             }
            
//         }

//         map.emplace(s[i],1);
//         maxLength = (map.size() > maxLength) ? map.size() : maxLength;
    
//         i++;
//     }

//     return maxLength;
// }

int main(){
    cout<<lengthOfLongestSubstring("");
    return 0;
}