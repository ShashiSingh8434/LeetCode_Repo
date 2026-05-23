#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    
    return 0;
}

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();

    int s = 0;
    int e = 0;
    int sum = 0;
    int count = INT_MAX;

    while(s <= e){
        if(sum >= target){
            count = min(count, e-s);
            sum -= nums[s];
            s++;
        }
        else if(e<n){
            sum += nums[e];
            e++;
        }
        else{
            if(e == n){
                break;
            }
        }

    }

    return (count == INT_MAX) ? 0 : count;
}