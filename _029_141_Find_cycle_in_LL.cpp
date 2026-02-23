#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 🔹 Key Idea

// Use Floyd’s Cycle Detection Algorithm (also called the Tortoise and Hare method).

// We move:

// One pointer slow → moves 1 step at a time

// One pointer fast → moves 2 steps at a time

// 👉 If there is a cycle, they will eventually meet.
// 👉 If there is no cycle, fast or fast.next becomes null.

// Why this works?
// Because in a cycle, the faster pointer will “lap” the slower one (like in a race track).

bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main(){
    
    return 0;
}