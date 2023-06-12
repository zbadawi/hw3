#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {

    //base case: list is empty
    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    Node* current = head; //keep track of current head
    head = head->next; //move onto next head for recursive call

    llpivot(head, smaller, larger, pivot);

    if (current->val <= pivot) {
        current->next = smaller;
        smaller = current;
    } else {
        current->next = larger;
        larger = current;
    }
}

