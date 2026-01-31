#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {

    int size = nums.size();
    vector<int> ascending(size);
    vector<int> descending(size);
    vector<int> ans(size);

    ascending[0] = (nums[0]);
    for (int i = 1; i < size; i++){
        ascending[i] = (ascending[i-1] * nums[i]);
    }

    descending[size-1] = nums[size-1];
    for (int i = size-2; i >= 0; i--){
        descending[i] = descending[i+1] * nums[i];
    }

    for (int i = 0; i < size; i++){
        if(i==0){
            ans[i] = descending[i+1];
        }
        else if(i==size-1){
            ans[i] = ascending[i-1];
        }
        else{
            ans[i] = ascending[i-1] * descending[i+1];
        }
    }
    
    return ans;
}

int main(){
    vector<int> para = {1,2,3,4};
    vector<int> ans = productExceptSelf(para);
    for(int i : ans){
        cout<<i<<" ";
    }
    return 0;
}