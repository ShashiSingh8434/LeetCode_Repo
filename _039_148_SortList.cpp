#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//--------------------------------------------------------------

// Linked List is best sorted using merge sort because of free movement of elements using pointers
// Arrays are best with the quicksort 


// QuickSort Version

ListNode* sortList(ListNode *head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    ListNode *pivot = head;
    ListNode *leftDummy = new ListNode(0);
    ListNode *rightDummy = new ListNode(0);

    ListNode *left = leftDummy;
    ListNode *right = rightDummy;

    while (pivot->next){
        if (pivot->next->val < pivot->val){
            ListNode *asdf = pivot->next;
            pivot->next = asdf->next;

            left->next = asdf;
            asdf->next = NULL;

            left = left->next;
        }
        else{
            ListNode *asdf = pivot->next;
            pivot->next = asdf->next;

            right->next = asdf;
            asdf->next = NULL;

            right = right->next;
        }
    }

    ListNode *leftSort = sortList(leftDummy->next);
    ListNode *rightSort = sortList(rightDummy->next);

    ListNode *leftHead = leftSort;

    while (leftSort && leftSort->next){
        leftSort = leftSort->next;
    }

    if (leftSort){
        leftSort->next = pivot;
    }
    else{
        leftHead = pivot;
    }
    pivot->next = rightSort;

    return leftHead;
}

//--------------------------------------------------------------

ListNode* merge(ListNode* left, ListNode* right){
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;

    while(left && right){
        if(left->val < right->val){
            temp->next = left;
            left = left->next;
        }
        else{
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }
    if(left){
        temp->next = left;
    }
    if(right){
        temp->next = right;
    }
    return dummy->next;
}

ListNode* mid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* sortList(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode* middle = mid(head);
    ListNode* temp = middle->next;
    middle->next = NULL;

    ListNode* left = sortList(head);
    ListNode* right = sortList(temp);

    return merge(left, right);
}