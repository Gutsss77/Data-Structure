// Implementation of Doubly Linked-list
/*
Structure of doubly linked-list (mota-mota🙏🏻)
ex : head->1-><-2-><-3->nullptr
*/

#include<iostream>
using namespace std;

int length = 0;

class D_node{
public:
    int data;
    D_node* left;
    D_node* right;

    D_node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void insertAtBegin(D_node* &head, D_node* &tail, int data) {
    D_node* node = new D_node(data);
    if (head == nullptr && tail == nullptr) {
        length++;
        head = tail = node;
    } else {
        node->right = head;
        head->left = node;
        head = node;
        length++;
    }
}

void removeFromBegin(D_node* &head){
    if(head == nullptr){
        return;
    }
    D_node* curr = head;
    head = head->right;
    if(head != nullptr){
        head->left = nullptr;
    }
    length--;
    delete curr;
}


void insertAtEnd(D_node* &head, D_node* &tail, int data){
    D_node* node = new D_node(data);
    if(head == nullptr && tail == nullptr){
        length++;
        head = tail = node;
    }else{
        tail->right = node;
        node->left = tail;
        tail = node;
        length++;
    }
}

void removeFromEnd(D_node* &tail){
    if(tail == nullptr){
        return;
    }
    D_node* curr = tail;
    tail = tail->left;
    if(tail != nullptr){
        tail->right = nullptr;
    }
    length--;
    delete curr;
}

void insertAtPosition(D_node* &head, D_node* &tail, int pos, int data){
    if(pos == 0){
        insertAtBegin(head, tail, data);
        return;
    }
    if(pos == length){
        insertAtEnd(head, tail, data);
        return;
    }
    if(pos < 0 || pos > length){
        cout << "Invalid Index!" << endl;
    }
    D_node* curr = head;
    D_node* newNode = new D_node(data);
    for(int i = 0; i < pos - 1; i++){
        curr = curr->right;
    }
    newNode->right = curr->right;
    if(curr->right != nullptr){
        curr->right->left = newNode;
    }
    curr->right = newNode;
    newNode->left = curr;
    length++;
}

void traverseD_list(D_node* &head){
    D_node* curr = head;

    cout << "head -> ";
    while(curr != nullptr){
        cout << curr->data << " <--> ";
        curr = curr->right;
    }
    cout << "nullptr" << endl;
    cout << "Current length of list : " << length << endl;
}

void reverseTraverse(D_node* &tail){
    D_node* curr = tail;
    while(curr != nullptr){
        cout << curr->data << " <--> ";
        curr = curr->left;
    }
    cout << "nullptr" << endl;
    cout << "Current length of list : " << length << endl;
}


int main(){
    D_node* head = nullptr;
    D_node* tail = nullptr;

    insertAtBegin(head, tail, 50);
    insertAtBegin(head, tail, 40);
    insertAtBegin(head, tail, 30);
    insertAtBegin(head, tail, 20);
    insertAtBegin(head, tail, 10);
    insertAtEnd(head, tail, 60);
    insertAtEnd(head, tail, 70);
    removeFromBegin(head);
    removeFromEnd(tail);
    insertAtPosition(head, tail, 3, 45);
    traverseD_list(head);
    reverseTraverse(tail);

    return 0;
}