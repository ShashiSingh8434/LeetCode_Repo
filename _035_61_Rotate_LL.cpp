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

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k==0){
        return head;
    }

    ListNode* temp = head;
    int count = 0;

    while(temp){
        count++;
        temp = temp->next;
    }
    
    temp = head;
    ListNode* rhead;
    ListNode* rtail;
    int point = count - (k%count);

    if(point == count){
        return head;
    }

    while(point>1){
        point--;
        temp = temp->next;
    }

    rhead = temp->next;
    temp->next = NULL;
    rtail = rhead;

    while(rtail->next){
        rtail = rtail->next;
    }
    rtail->next = head;

    return rhead;
}


//--------------------------------------------------------------(Optimised)

ListNode* rotateRightOptimised(ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0){
        return head;
    }

    // Find length and tail
    ListNode* tail = head;
    int len = 1;

    while(tail->next){
        len++;
        tail = tail->next;
    }

    k = k % len;

    if(k == 0){
        return head;
    }

    // Make circular list
    tail->next = head;

    // Find new tail
    int steps = len - k;
    ListNode* newTail = head;

    while(steps > 1){
        newTail = newTail->next;
        steps--;
    }

    // Break circle
    ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}