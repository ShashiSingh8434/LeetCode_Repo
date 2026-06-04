#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    return 0;
}

// int sum(char a, char b, int c){
//     if(a == '1' && b == '1'){
//         if(c == 0){
//             return 0;
//         }
//         else{
//             return 1;
//         }
//     }
//     else if(a == '0' && b == '0'){
//         if(c == 0){
//             return 0;
//         }
//         else{
//             return 1;
//         }
//     }
//     else{
//         if(c == 0){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
// }

// int decideCarry(char a, char b, int c){
//     if(a == '1' && b == '1'){
//         return 1;
//     }
//     else if(a == '0' && b == '0'){
//         return 0;
//     }
//     else{
//         if(c == 0){
//             return 0;
//         }
//         else{
//             return 1;
//         }
//     }
// }

// string addBinary(string a, string b) {
//     int n1 = a.length();
//     int n2 = b.length();
//     int res = 0;
//     int carry = 0;
//     int counter = 1;
//     int big = max(n1, n2);
// 
//     vector<int> ans(big+1, 0);
//     string output = "";
// 
//     for(int i = big; i >= 0; i--){
//         int x = n1-counter;
//         int y = n2-counter;
//         counter++;
// 
//         if(x>=0 && y>=0){
//             res = sum(a[x], b[y], carry);
//             carry = decideCarry(a[x], b[y], carry);                
//         }
//         else if(x>=0){
//             res = sum(a[x], '0', carry);
//             carry = decideCarry(a[x], '0', carry);                
//         }
//         else if(y>=0){
//             res = sum('0', b[y], carry);
//             carry = decideCarry('0', b[y], carry);                
//         }
//         else{
//             res = carry;
//             carry = 0;
//         }
// 
//         ans[i] = res;
//     }
// 
//     bool flag = false;
//     for(int i : ans){
//         if((n1 == 1 && n2 == 1 && a[0] == '0' && b[0] == '0')){
//             output = "0";
//             break;
//         }
//         if(i == 1){
//             flag = true;
//         }
//         if(flag){
//             output += to_string(i);
//         }
//     }
// 
// 
//     return output;
// }


string addBinary(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    string ans = "";

    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if(i >= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';

        ans += (sum % 2) + '0';
        carry = sum / 2;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}


