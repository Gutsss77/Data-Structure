#include<iostream>
using namespace std;

/*
Both functions reverse a linked list 
ex : 1->2->3->4 
     4->3->2->1
*/

/*
Iterative way
Space complexity : O(1)
Time Complexity : O(n)
*/
Node* reverseListIterative(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
/*
Recursive way
Space complexity : O(n) due to function stack
Time Complexity : O(n)
*/
Node* reverseListRecursive(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}