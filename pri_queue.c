#include <stdlib.h>
#include <stdio.h>
#include "pri_queue.h"
/** @file pri_queue.c */
static Node_ptr_t head = NULL;
/**
 * Insert a Node into a priority queue.
 * @param priority
 * @param data
 * @author Ryan Murari
 */
void PQ_insert(int priority, char *data) {
// add your code here
    Node_t *newNode = (Node_t*)malloc(sizeof(Node_t));

    newNode->data = data; 
    newNode->priority = priority; 
    newNode->next = NULL;

    if (head == NULL || head->priority <= newNode->priority) {

        newNode->next = head;
        head = newNode;

    }
    else { //priority is less than head
        Node_ptr_t start = head;
        //iterate till priority is greater than start.next.priority
        while (start->next !=NULL && start->next->priority > priority) {
            start = start->next;
        }
        newNode->next = start->next;
        start->next = newNode;

   }
}
/**
 * Delete and return the node with the highest priority.
 * @return The highest priority Node.
 */
Node_ptr_t PQ_delete() {
    // add your code here
    //unlink node from rest of linked list
    Node_ptr_t temp = head;
    head = head->next;
    return head;
}

/**
 * Do NOT modify this function.
 * @return A pointer to the head of the list.  (NULL if list is empty.)
 */
Node_ptr_t PQ_get_head() {
    return head;
}

/**
 * Do NOT modify this function.
 * @return the number of items in the queue
 */
int PQ_get_size() {
    int size = 0;
    Node_ptr_t tmp;
    for(tmp = head; tmp != NULL; tmp = tmp->next, size++)
        ;
    return size;
}


