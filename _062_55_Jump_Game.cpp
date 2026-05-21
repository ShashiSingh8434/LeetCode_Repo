#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}

// greedy approach------------------------(optimal)

bool canJump(vector<int>& nums) {
    int n = nums.size();
    
    int goal = n - 1;

    for(int i = n - 2; i >= 0; i--) {
        if(i + nums[i] >= goal) {
            goal = i;
        }
    }

    return goal == 0;
}

// DP approach--------------------------------- (my approach)

// bool check(vector<int>& nums, vector<int>& dp, int i, int n) {
//     if(i >= n - 1) {
//         return true;
//     }

//     if(nums[i] == 0) {
//         return false;
//     }

//     if(dp[i] != -1) {
//         return dp[i];
//     }

//     int jump = nums[i];

//     while(jump > 0) {
        
//         if(check(nums, dp, i + jump, n)) {
//             return dp[i] = true;
//         }

//         jump--;
//     }

//     return dp[i] = false;
// }

// bool canJump(vector<int>& nums) {
    
//     int n = nums.size();

//     vector<int> dp(n, -1);

//     return check(nums, dp, 0, n);
// }