#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int gcd(int a, int b) {                
    while (b != 0) {
        int temp = b;                
        b = a % b;
        a = temp;
    }
    return a;
}

ListNode* insertGreatestCommonDivisors(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* left = head;
    ListNode* right = head->next;

    while(right){
        int val = gcd(left->val, right->val);

        ListNode* temp = new ListNode(val);

        left->next = temp;
        temp->next = right;

        left = left->next->next;
        right = right->next;
    }
    return head;
}