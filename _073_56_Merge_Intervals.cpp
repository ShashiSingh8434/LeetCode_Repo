#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    return 0;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;
    int n = intervals.size();

    int s = -1;
    int e = -1;

    for(auto i : intervals){
        if(i[0] > e){
            if(s!=-1){
                ans.push_back({s,e});
            }
            s = i[0];
            e = i[1];
        }
        else{
            e = max(e, i[1]);
        }
    }
    ans.push_back({s,e});
    
    return ans;
}