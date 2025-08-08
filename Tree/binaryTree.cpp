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

bool searchInBST(Node* &root, int val){
    if(root == nullptr) {return false;}
    if(root->data == val) {return true;}
    else if(val < root->data) {return searchInBST(root->left, val);}
    else if(val > root->data) {return searchInBST(root->right, val);}
    else {return false;}
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
    if(searchInBST(root, 60)){
        std::cout << "\nValue present\n";
    }else{
        std::cout << "\nValue not present\n";
    }

    delete root;

    return 0;
}