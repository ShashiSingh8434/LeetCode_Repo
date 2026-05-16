#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    
    return 0;
}

int thirdMax(vector<int>& nums) {
    vector<int> max(3, INT_MIN);
    int count = 0;
    bool chance = true;

    for(int i : nums){
        if(i>max[0]){
            max[2] = max[1];
            max[1] = max[0];
            max[0] = i;
            count++;
        }
        else if(i>max[1] && i!=max[0]){
            max[2] = max[1];
            max[1] = i;
            count++;
        }
        else if(i>max[2] && i!=max[0] && i!=max[1]){
            max[2] = i;
            count++;
        }
        else if(i == INT_MIN && chance){
            count++;
            chance = false;
        }
    }

    if(count >= 3){
        return max[2];
    }
    else{
        return max[0];
    }
}