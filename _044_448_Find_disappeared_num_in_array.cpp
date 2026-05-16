#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    vector<bool> n(nums.size(), true);

    for(int i : nums){
        n[i-1] = false;
    }

    for(int i=0; i<n.size(); i++){
        if(n[i]){
            ans.push_back(i+1);
        }
    }

    return ans;
}