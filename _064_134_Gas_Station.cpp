#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int gasSum = 0;
    int costSum = 0;

    for(int i : gas){
        gasSum += i;
    }

    for(int i : cost){
        costSum += i;
    }

    if(gasSum < costSum){
        return -1;
    }

    int tank = 0;
    int start = 0;
    int n = gas.size();

    for(int i = 0; i < n; i++) {
        tank += gas[i] - cost[i];

        if(tank < 0) {
            start = i + 1;
            tank = 0; 
        }
    }

    return start;
}