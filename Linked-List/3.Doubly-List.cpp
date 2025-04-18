#include<iostream>
using namespace std;

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
        head = tail = node;
    } else {
        node->right = head;
        head->left = node;
        head = node;
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
    delete curr;
}


void insertAtEnd(D_node* &head, D_node* &tail, int data){
    D_node* node = new D_node(data);
    if(head == nullptr && tail == nullptr){
        head = tail = node;
    }else{
        tail->right = node;
        node->left = tail;
        tail = node;
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
    delete curr;
}

void traverseD_list(D_node* &head){
    D_node* curr = head;

    while(curr != nullptr){
        cout << curr->data << " -> ";
        curr = curr->right;
    }
    cout << "nullptr" << endl;
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
    traverseD_list(head);

    return 0;
}