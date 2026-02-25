#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res = new ListNode(0);
    ListNode* ans = res;

    int temp = 0;
    int sum = 0;
    int digit = 0;
    int carry = 0;

    while (l1 || l2){
        if(l1 && l2){
            sum = l1->val + l2->val + carry;
            carry = 0;
            if(sum > 9){
                digit = sum%10;
                carry = 1;
            }
            else{
                digit = sum;
            }

            ans->next = new ListNode(digit);
            l1 = l1->next;
            l2 = l2->next;
        }
        else if(l1){
            sum = l1->val + carry;
            carry = 0;
            if(sum > 9){
                digit = sum%10;
                carry = 1;
            }
            else{
                digit = sum;
            }

            ans->next = new ListNode(digit);
            l1 = l1->next;
        }
        else{
            sum = l2->val + carry;
            carry = 0;
            if(sum > 9){
                digit = sum%10;
                carry = 1;
            }
            else{
                digit = sum;
            }

            ans->next = new ListNode(digit);
            l2 = l2->next;
        }

        ans = ans->next;
    }
    
    if(carry != 0){            
        ans->next = new ListNode(carry);
        carry = 0;
    }

    return res->next;
}

int main(){
    
    return 0;
}