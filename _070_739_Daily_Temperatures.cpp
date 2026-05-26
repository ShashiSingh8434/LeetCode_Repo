#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    
    return 0;
}

// vector<int> dailyTemperatures(vector<int>& temperatures) {

//     int n = temperatures.size();
//     vector<int> ans(n, 0);

//     stack<int> st;

//     for (int i = n - 1; i >= 0; i--) {

//         while (!st.empty() &&
//                temperatures[st.top()] <= temperatures[i]) {
//             st.pop();
//         }

//         if (!st.empty()) {
//             ans[i] = st.top() - i;
//         }

//         st.push(i);
//     }

//     return ans;
// }

vector<int> dailyTemperatures(vector<int>& temp) {

    int n = temp.size();
    vector<int> ans(n, 0);

    int left = n - 2;

    while (left >= 0) {

        int right = left + 1;

        while (right < n && temp[right] <= temp[left]) {

            if (ans[right] == 0) {
                right = n;    
            }
            else {
                right += ans[right]; 
            }
        }

        if (right < n) {
            ans[left] = right - left;
        }

        left--;
    }

    return ans;
}