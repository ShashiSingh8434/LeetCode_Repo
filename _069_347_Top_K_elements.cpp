#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(){
    
    return 0;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_set<int> st;
    unordered_map<int, int> mp;

    for(int i : nums){
        st.insert(i);
    }

    for(int i : nums){
        if(mp.count(i)){
            mp[i] += 1;
        }
        else{
            mp[i] = 1;
        }
    }

    while(k--){
        auto maxIt = mp.begin();

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (it->second > maxIt->second) {
                maxIt = it;
            }
        }
        ans.push_back(maxIt->first);
        mp.erase(maxIt);
    }
    return ans;
}