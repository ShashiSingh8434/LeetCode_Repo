#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

Node* flatten(Node* head) {
    if(head == NULL || (head->next == NULL && head->child == NULL)){
        return head;
    }
    Node* temp = head;
    Node* right = head->next;

    while(temp){
        if(temp->child){
            if(right){
                right->prev = NULL;
            }

            temp->next = temp->child;
            temp->child->prev = temp;
            temp->child = NULL;

            Node* start = flatten(temp->next);
            while(start && start->next){
                start = start->next;
            }
            start->next = right;
            if(right){
                right->prev = start;
            }

            temp = start;
        }

        if(right){
            temp = temp->next;
            right = right->next;
        }
        else{
            return head;
        }
    }
    return head;
}