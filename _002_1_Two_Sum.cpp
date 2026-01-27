#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for(int i=0; i<nums.size(); i++){
        int complement = target - nums[i];

        if(mp.find(complement) != mp.end()){
            return {mp[complement],i};
        }

        mp[nums[i]] = i;
    }
    return {-1, -1};
}

// vector<int> twoSum(vector<int>& nums, int target) {
//     vector<int> ans;
//     for(int i=0; i<nums.size(); i++){
//         for(int j=0; j<nums.size(); j++){
//             if(i != j){
//                 if(nums[i] + nums[j] == target){
//                     ans.push_back(i);
//                     ans.push_back(j);
//                     return ans;
//                 }
//             }
//         }
//     }
//     ans.push_back(-1);
//     return ans;
// }

int main(){
    vector<int> para = {2,7,11,15};
    vector<int> res = twoSum(para, 9);
    for(int i: res){
        cout<<i<<" ";
    }

    return 0;
}