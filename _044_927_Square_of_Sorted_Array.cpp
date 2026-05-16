#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    return 0;
}

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> neg;
    vector<int> pos;

    for(int i : nums){
        if(i<0){
            neg.push_back(i*i);
        }
        else{
            pos.push_back(i*i);
        }
    }

    if(pos.empty()){
        reverse(neg.begin(),neg.end());
        return neg;
    }
    if(neg.empty()){
        return pos;
    }

    int i = pos.size()-1;
    int j = 0;

    while(i>=0 && j<neg.size()){
        if(pos[i] <= neg[j]){
            pos.insert(pos.begin()+i+1, neg[j]);
            j++;
        }
        else{
            i--;
        }
    }
    if(j<neg.size()){
        for(int i = j; i<neg.size(); i++){
            pos.insert(pos.begin(), neg[i]);
        }
    }

    return pos;
}