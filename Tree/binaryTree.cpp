#include <iostream>

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data = 0) : data(data), left(nullptr), right(nullptr) {}
};

void insertInBST(Node* &root, int val){
    if(root == nullptr){
        root = new Node(val);
        return;
    }
    if(val < root->data){
        insertInBST(root->left, val);
    }
    else if(val > root->data){
        insertInBST(root->right, val);
    }else{
        std::cout << "Duplicate value!" << "\n";
        return;
    }
}

void inorderTraversal(Node* &root){
    if(root == nullptr){
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right); 
}


int main(){
    Node* root = nullptr;

    while(true){
        int val;
        std::cout << "Enter value : ";
        std::cin >> val;
        if(val == -1) break;
        else{
            insertInBST(root, val);
        }
    }

    inorderTraversal(root);

    delete root;

    return 0;
}