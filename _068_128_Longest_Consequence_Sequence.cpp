#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    
    return 0;
}

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> asdf;
    int count = 0;

    for(int i : nums){
        asdf.insert(i);
    }

    for(int n : asdf){
        int temp = 0;

        if(asdf.count(n - 1)){
            continue;
        }

        while(asdf.find(n) != asdf.end()){
            temp++;
            n++;
        }

        count = max(count, temp);
    }
    return count; 
}