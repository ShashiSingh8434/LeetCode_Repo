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

ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* next = NULL;
    ListNode* curr = head;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
void reorderList(ListNode* head) {
    ListNode* temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }

    temp = head;
    int half = count/2+1;
    while(half>1){
        half--;
        temp = temp->next;
    }
    ListNode* halff = temp->next;
    temp->next = NULL;

    ListNode* first = head;
    ListNode* second = reverse(halff);

    while(second){
        ListNode* tempOne = first->next;
        ListNode* tempSecond = second->next;

        first->next = second;
        second->next = tempOne;
        
        first = tempOne;
        second = tempSecond;
    }
}

// ---------------------------------------------------------------

ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    bool hasCycle = false;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            hasCycle = true;
            break;
        }
    }
    if(!hasCycle){
        return NULL;
    }

    ListNode* inCycleMeet = slow;
    ListNode* newHead = head;

    while(inCycleMeet != newHead){
        inCycleMeet = inCycleMeet->next;
        newHead = newHead->next;
    }
    return newHead;
}