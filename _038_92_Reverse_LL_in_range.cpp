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

ListNode* reverse(ListNode* head, int count){
    ListNode* prev = NULL;
    ListNode* next = NULL;
    ListNode* curr = head;

    ListNode* rtail = head;

    while(count){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

        count--;
    }
    rtail->next = curr;
    return prev;
}
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    left--;
    right--;

    ListNode* temp = head;
    for(int i = 0; i < left-1; i++){
        temp = temp->next;
    }
    if(left == 0){
        temp = reverse(temp,  right-left+1);
        head = temp;
    }
    else{
        temp->next = reverse(temp->next, right-left+1);
    }
    return head;
}

//--------------------------------------------------------------

