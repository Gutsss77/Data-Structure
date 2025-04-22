//Implementatin of linked list : all CRUD operations
//using class (structure can also be used)
/*
structure example of linked-list :
    (head)1 -> 2 -> 3 -> 4(tail)
*/
#include<iostream>
#include<vector>
#include<set>
#include<map>

using std::cout;
using std::map;
using std::vector;
using std::endl;
using std::max;
using std::set;

struct node{
    int data;
    node* next = nullptr;
};

//Singly Linked-list || node is created
class Node{
public:
    int data;
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
size_t length = 0;

//Insertion at begining
/*
-> create a new node with data
-> check if the list is empty : if yes created node is the first
-> else add(new node) to the list and place the head to new node 
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
        length++;
    }else{
        newNode->next = head; //else add the new node to head of teh list
        head = newNode;
        cout << "New node added at the head of the list with data : " << newNode->data << endl;
        length++;
    }
}

// Deletion from begining of list
void deleteFromBegining(){
    if(head == nullptr){
        return;
    }
    length--;
    if(head == tail){
        tail = nullptr;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

//Insertion at end
/*
-> create a new node with data
-> check if the list is empty : if yes created node is the first
-> else add the new node to the end of list using the tail
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
        length++;
    }else{
        tail->next = newNode;
        tail = newNode;
        cout << "New node added at the tail of the list with data : " << newNode->data << endl;
        length++;
    }
}

//Deletion from end of list
void deleteFromEnd(){
    if(head == nullptr){
        return;
    }
    length--;
    if(head == tail){
        tail = nullptr;
        return;
    }
    Node* prev = nullptr;
    Node* curr = head;
    while(curr->next != nullptr){
        prev = curr;
        curr = curr->next;
    }
    prev->next = nullptr;
    delete curr;
    tail = prev;
}

//Insertion at given position : 
/*
-> if pos == 0 then use insertionAtBegining()
-> if pos > length then use insertionAtEnd()
-> create a new node with data
-> take a temp node and use pos to reach the node just previous to where the node needs to be added
-> place the new node there and place the next of new node to where the previous node is pointing 
1(head) -> 2 -> 3(tail) before
5 need to be at pos 1 (ex of pos : 0,1,2)
1(head) -> 5 -> 2 -> 4(tail)
*/
void InsertionAtPositionNode(int data, int pos){
    if(pos == 0){
        insertAtBegining(data);
        return;
    }
    if(pos == length){
        insertAtEnd(data);
        return;
    }
    if(pos < 0 || pos > length){
        cout << "Invalid Positon !" << endl;
    }
    Node* newNode = new Node(data);  //new node with data
    Node* temp = head; //for tracking the node , after which the new node is to be placed
    for(int i = 0; i < pos - 1; i++){ //go to the node just before the position
        temp = temp->next; 
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "New node added at postion " << pos << " with data : " << data << endl;
    length++;
}

//Deletion from specific position
void deleteFromPosition(int pos){
    if(pos < 0){
        cout << "Invalid Position!" << "\n";
        return;
    }
    if(pos > length){
        cout << "Invalid Position" << "\n";
        return;
    }
    length--;
    Node* curr = head;
    Node* temp = nullptr;
    for(int i = 0; i < pos-1; i++){
        curr = curr->next;
    }
    temp = curr->next;
    curr->next = temp->next;
    cout << "Node deleted at pos " << pos << " with data : " << temp->data << "\n";
    delete temp;

}

//this function helps in traversing  the list
void traverseTheList(){
    cout << "Current length of list : " << length << endl;
    Node* curr = head; //assigning the list head to pointer for tarversal
    while(curr != nullptr){
        cout << curr->data << " -> "; //print data of current node
        curr = curr->next; //move to next node
    }
    cout << "nullptr" << endl; 
}

int largestInList(){
    int maxNum = head->data;
    Node* curr = head;
    while(curr != nullptr){
        maxNum = max(maxNum, curr->data);
        curr = curr->next;
    }
    return maxNum;
}

void removeDuplicate(){
    set<int> seen;
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (seen.count(curr->data)) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            length--;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
}

void reverseDisplay(){
    vector<int> store;
    Node* curr = head;
    while(curr != nullptr){
        store.push_back(curr->data);
        curr = curr->next;
    }
    for(int i = store.size() - 1; i >= 0; i--){
        cout << store[i] << " ";
    }
    cout << endl;
}

map<int, int> freqOfeachElement() {
    map<int, int> freq;
    Node* curr = head;

    while (curr != nullptr) {
        freq[curr->data]++;
        curr = curr->next;
    }

    return freq;
}



int main(){

    insertAtBegining(20);
    insertAtBegining(10);
    insertAtEnd(10);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);
    insertAtEnd(70);
    InsertionAtPositionNode(45, 2);
    traverseTheList();
    int maxNum = largestInList();
    cout << "Larget is : " << maxNum << endl;
    removeDuplicate();
    traverseTheList();
    reverseDisplay();
    map<int, int> freq = freqOfeachElement();
    for(auto i : freq){
        cout << i.first << " : " << i.second << endl;
    }
    deleteFromBegining();
    deleteFromEnd();
    traverseTheList();
    deleteFromPosition(3);
    traverseTheList();

    return 0;
}