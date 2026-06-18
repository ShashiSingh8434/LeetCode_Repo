#include <iostream>
using namespace std;

int main(){
    
    return 0;
}

int myAtoi(string s) {
    int i = 0;
    int n = s.length();
    
    while (i < n && isspace(s[i])) {
        i++;
    }
    
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-') {
            sign = -1;
        }
        i++; 
    }
    
    long result = 0;
    while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        
        if (sign * result <= INT_MIN) return INT_MIN;
        if (sign * result >= INT_MAX) return INT_MAX;
        
        i++;
    }
    
    return (int)(sign * result);
}