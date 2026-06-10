#include <iostream>
using namespace std;

int main(){
    
    return 0;
}

bool checkIfPangram(std::string sentence) {
    bool seen[26] = {false};
    int uniqueCount = 0;
    
    for (char c : sentence) {
        int index = c - 'a';
        
        if (!seen[index]) {
            seen[index] = true;
            uniqueCount++;
        }
    }
    
    return uniqueCount == 26;
}