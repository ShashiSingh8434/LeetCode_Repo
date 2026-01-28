#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int prefix = 0;
    int minPrefix = 0;  
    int maxSum = nums[0];

    for (int i = 0; i < nums.size(); i++) {
        prefix += nums[i];
        maxSum = max(maxSum, prefix - minPrefix);
        minPrefix = min(minPrefix, prefix);
    }

    return maxSum;
}
      

//BRUTE FORCE METHOD--------------------

// int maxSubArray(vector<int>& nums) {

//     vector<int> maxList;
//     int perMax;

//     for (int i = 0; i < nums.size(); i++){
//         int perMax = nums[i];
//         int tempMax = nums[i];

//         for (int j = i+1; j < nums.size(); j++){
//             tempMax += nums[j];

//             if(tempMax > perMax){
//                 perMax = tempMax;
//             }
//         }
//         maxList.push_back(perMax);
//     }

//     int res = maxList[0];

//     for(int i : maxList){
//         res = (i > res) ? i : res;
//     }

//     return res;
        
// }

int main(){
    vector<int> para = {5,4,-1,7,8};
    cout<<maxSubArray(para);
    return 0;
}