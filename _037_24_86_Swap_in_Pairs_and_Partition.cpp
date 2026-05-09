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

ListNode* swap(ListNode* head){
    ListNode* first = head;
    ListNode* sec = head->next;

    first->next = sec->next;
    sec->next = first;

    return sec;
}
ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* nextPair = swapPairs(head->next->next);
    head->next->next = nextPair;
    ListNode* rev = swap(head);

    return rev;
}

//--------------------------------------------------------------

ListNode* partition(ListNode* head, int x) {
    ListNode* dummy = new ListNode(0);
    ListNode* rest = new ListNode(0);

    ListNode* small = dummy;
    ListNode* big = rest;

    ListNode* temp = head;

    while(temp){
        ListNode* tempNext = temp->next;

        if(temp->val < x){
            small->next = temp;
            small = small->next;
        }
        else{
            big->next = temp;
            big = big->next;
        }
        temp->next = nullptr;
        temp = tempNext;
    }
    small->next = rest->next;
    head = dummy->next;
    
    return head;
}