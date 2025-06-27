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
    std::cout << "For left of " << val << std::endl;
    insert(root->left);
    std::cout << "For right of " << val << std::endl;
    insert(root->right);
}

void inorder(Node* &root){
    if(root == nullptr) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node* root;
    insert(root);
    std::cout << "\n";
    inorder(root);

    delete root;

    return 0;
}