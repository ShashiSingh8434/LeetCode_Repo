#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteMiddle(ListNode* head) {
    if(head == NULL){
        return head;
    }
    if(head->next == NULL){
        ListNode* asdf = new ListNode(0);
        return asdf->next;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* temp = slow->next;
    slow->next = temp->next;
    temp->next = NULL;

    return head;
}