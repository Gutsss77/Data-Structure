#include <iostream>

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

void insert(Node* &root){
    int val;
    std::cout << "Enter Number : ";
    std::cin >> val;
    if(val == -1){
        return;
    }
    root = new Node(val);
    std::cout << "Left of " << val << std::endl;
    insert(root->left);
    std::cout << "Right of " << val << std::endl;
    insert(root->right);
}

void postorder(Node* &root){
    if(root == nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

int main(){
    Node* root;
    insert(root);
    std::cout << std::endl;
    postorder(root);
    return 0;
}