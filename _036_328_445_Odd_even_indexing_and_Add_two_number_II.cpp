#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//--------------------------------------------------------------

ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode* even = head;
    ListNode* odd = head->next;
    ListNode* tail = odd;

    while(even->next && tail->next){
        even->next = tail->next;
        even = even->next;
        tail->next = even->next;
        tail = tail->next;
    }

    even->next = odd;
    return head;
}

//--------------------------------------------------------------

ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    ListNode* dummy = new ListNode(0);
    ListNode* ans = dummy;

    int sum = 0;
    int carry = 0;

    while(l1 || l2 || carry){

        sum += carry;

        if(l1){
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2){
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum/10;
        ans->next = new ListNode(sum%10);
        ans = ans->next;
        
        sum = 0;
    }
    return reverse(dummy->next);
}
