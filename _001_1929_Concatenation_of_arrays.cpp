#include <iostream>
#include <vector>
using namespace std;

vector<int> getConcatenation(vector<int>& nums) {
    vector<int> ans(2*nums.size());
    for (int i = 0; i < nums.size(); i++){
        ans[i] = nums[i];
        ans[i + nums.size()] = nums[i];        
    }
    
    return ans;
}

int main(){
    vector<int> a = {1,2,1};
    vector<int> result = getConcatenation(a);
    for (int i : result) {
        cout << i << " ";
    }
    
    return 0;
}
