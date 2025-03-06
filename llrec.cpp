#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    if (head == NULL){
        return;
    }

    // save next node in "head" list so that we do not lose track of list
    Node* nextElement = head -> next;

    if (head -> val > pivot) {
        // disconnect node from list by setting next value to null. Set current node of larger to current/ head node of list
        head -> next = NULL;  
        larger = head;

        // recursively call function llpivot(), moving onto next element in list "smaller" because 
        // current head of smaller now points to current element/ head of first list 
        llpivot(nextElement, smaller, larger -> next, pivot);
    } else {
        // disconnect node from list by setting next value to null. Set current node of smaller to current/ head node of list
        head -> next = NULL;
        smaller = head;

        // recursively call function llpivot(), moving onto next element in list "larger" because 
        // current head of larger now points to current element/ head of first list 
        llpivot(nextElement, smaller -> next, larger, pivot);
    } 

    // ensures list is empty and set to null 
    head = NULL;
}
