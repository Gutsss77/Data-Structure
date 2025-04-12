//Most important functions and question in linked list with implementation
/*
1. Reverse list (both iterative and recursive way)
2. Detect Cycle in linked-list 
3. Merge two sorted linked list
*/
#include<iostream>
using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Global head, tail, and length
Node* head = nullptr;
Node* tail = nullptr;
size_t length = 0;

// Insert at beginning for main list
void insertAtBeginning(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    length++;
    cout << "Insertion successful!" << endl;
}

// Insert at beginning for another list (using reference)
void insertAtBeginning(int data, Node*& head2, Node*& tail2) {
    Node* newNode = new Node(data);
    if (head2 == nullptr) {
        head2 = tail2 = newNode;
    } else {
        newNode->next = head2;
        head2 = newNode;
    }
    cout << "Insertion successful!" << endl;
}

// Traverse list
void traverseTheList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}

// Iterative Reverse
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

// Recursive Reverse
Node* reverseListRecursive(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

// Detect Cycle using Floyd’s Tortoise and Hare
bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }
    return false;
}

// Merge two sorted linked lists
Node* mergeSortedLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    Node* dummy = new Node(-1);
    Node* tail = dummy;

    while (l1 && l2) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1) tail->next = l1;
    else tail->next = l2;

    Node* mergedHead = dummy->next;
    delete dummy;
    return mergedHead;
}

int main() {
    Node* head2 = nullptr;
    Node* tail2 = nullptr;

    // List 1
    insertAtBeginning(50);
    insertAtBeginning(40);
    insertAtBeginning(30);
    insertAtBeginning(20);
    insertAtBeginning(10);
    cout << "List 1: ";
    traverseTheList(head);

    // List 2
    insertAtBeginning(55, head2, tail2);
    insertAtBeginning(45, head2, tail2);
    insertAtBeginning(35, head2, tail2);
    insertAtBeginning(25, head2, tail2);
    insertAtBeginning(15, head2, tail2);
    cout << "List 2: ";
    traverseTheList(head2);

    // Reverse Iteratively
    Node* reversedIter = reverseListIterative(head);
    cout << "List 1 Reversed (Iterative): ";
    traverseTheList(reversedIter);

    // Reverse Recursively
    Node* reversedRec = reverseListRecursive(reversedIter);
    cout << "List 1 Reversed Back (Recursive): ";
    traverseTheList(reversedRec);

    // Merge lists
    Node* mergedList = mergeSortedLists(reversedRec, head2);
    cout << "Merged Sorted List: ";
    traverseTheList(mergedList);

    // Detect cycle
    if (detectCycle(mergedList)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected!" << endl;
    }

    return 0;
}
