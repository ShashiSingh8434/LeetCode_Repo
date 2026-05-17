#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    
    return 0;
}

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> mp;

    for(int i=0; i<nums.size(); i++){
        if(mp.find(nums[i]) != mp.end()){
            return true;
        }
        else{
            mp[nums[i]] = 1;
        }
    }
    return false;
}