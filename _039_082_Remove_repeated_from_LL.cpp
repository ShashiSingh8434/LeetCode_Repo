#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head){
    ListNode* dummy = new ListNode(0);
    ListNode* prev = dummy;
    ListNode* temp = head;

    prev->next = temp;

    while(prev->next){
        if(temp->next && temp->val == temp->next->val){
            int val = temp->val;

            while(temp && temp->val == val){
                ListNode* asdf = temp->next;
                temp->next = NULL;

                prev->next = asdf;
                temp = asdf;
            }
        }
        else{
            prev = prev->next;
            temp = temp->next;
        }
    }
    return dummy->next;
}