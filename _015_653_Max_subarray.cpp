#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// double findMaxAverage(vector<int>& nums, int k) {
//     int n = nums.size() - 1;
//     double max = INT32_MIN;
//     if(n==1){
//         double ans = nums[0];
//         return ans;
//     }
//     for (int i = 0; i <= n-k+1; i++){
//         double temp = 0;
//         for (int j = i; (j < i+k); j++){
//             temp += nums[j];
//         }
//         if((temp / k) > max){
//             max = temp/k;
//         }
//     }
//     return max;
// }


double findMaxAverage(vector<int>& nums, int k){
    double sum = 0;
    double max = -1e9;
    int count = 0;

    
    for (int i = 0; i < nums.size(); i++){
        sum += nums[i];
        count++;
        

        if(count == k){            
            double tempmax = sum/k;
            max = (tempmax > max) ? tempmax : max;
            sum -= nums[i-k+1];
            count--;
        }
    }
    return max;
}

double findMaxAverage_best(vector<int>& nums, int k) {
    double sum = 0;
    double maxAvg = INT32_MIN;
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        count++;

        if (count == k) {
            maxAvg = max(maxAvg, sum / k);
            sum -= nums[i - k + 1];
            count--;
        }
    }
    return maxAvg;
}

int main(){
    // vector<int> nums = {1,12,-5,-6,50,3};
    vector<int> nums = {5};
    cout<<findMaxAverage(nums, 1);

    return 0;
}