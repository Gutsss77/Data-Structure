//Implementatin of linked list : all CRUD operations
//using class (structure can also be used)
/*
structure example of linked-list :
    (head)1 -> 2 -> 3 -> 4(tail)
*/
#include<iostream>
using namespace std;

//Singly Linked-list || node is created
class Node{
public:
    int data;;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

//Global declaration of head and tail 
//Helps in tracking the head of list and tail of list
Node* head = nullptr;
Node* tail = nullptr;
int length = 0;

//Insertion at begining
/*
->create a new node with data
->check if the list is empty : if yes created node is the first
->else add(new node) to the list and place the head to new node 
ex : 2 is in list, 1 needs to be added (at first 2 will be the head and tail)
after adding 1 to head of the list, head goes to 1
2(head)(tail) before
1(head) -> 2(tail) after
*/
void insertAtBegining(int data){
    Node* newNode = new Node(data);
    if(head == nullptr && tail == nullptr){ //if newNode is the first in list
        head = newNode;
        tail = newNode;
        cout << "First node is created with data : " << newNode->data << endl;
    }else{
        newNode->next = head; //else add the new node to head of teh list
        head = newNode;
        cout << "New node added at the head of the list with data : " << newNode->data << endl;
    }
}

//Insertion at end
/*
->create a new node with data
->check if the list is empty : if yes created node is the first
->else add the new node to the end of list using the tail
ex : 3 needs to be added to last of list which is : 1(head) -> 2(tail)
means after 2, so place the node after the tail and make it the new tail
1(head) -> 2 -> 3(tail)
*/
void insertAtEnd(int data){
    Node* newNode = new Node(data);
    if(head == nullptr && tail == nullptr){
        head = newNode;
        tail = newNode;
        cout << "First node is created with data : " << newNode->data << endl;
    }else{
        tail->next = newNode;
        tail = newNode;
        cout << "New node added at the tail of the list with data : " << newNode->data << endl;
    }
}


//this function helps in traversing  the list
void traverseTheList(){
    Node* curr = head; //assigning the list head to pointer for tarversal
    while(curr != nullptr){
        cout << curr->data << " -> "; //print data of current node
        curr = curr->next; //move to next node
    }
    cout << "nullptr" << endl; 
}

int main(){
    insertAtBegining(20);
    insertAtBegining(10);
    insertAtEnd(30);
    insertAtEnd(40);
    traverseTheList();

    return 0;
}