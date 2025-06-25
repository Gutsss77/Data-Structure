#include <iostream>

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data = 0){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void insertPreorder(Node* &root){
    int val;
    std::cout << "Enter value : ";
    std::cin >> val;
    if(val == -1){
        return;
    }
    root = new Node(val);
    std::cout << "For left of " << val << std::endl;
    insertPreorder(root->left);
    std::cout << "For right of " << val << std::endl;
    insertPreorder(root->right);
}

void preorder(Node* &root){
    if(root == nullptr){
        return;
    }
    preorder(root->left);
    preorder(root->right);
    std::cout << root->data << " ";
}

int main(){
    Node* root;
    insertPreorder(root);
    std::cout << "Preorder traversal(left right root) : ";
    preorder(root);
    std::cout << std::endl;

    return 0;
}