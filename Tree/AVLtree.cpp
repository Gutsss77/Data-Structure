#include <algorithm>
#include <iostream>

class TreeNode{
public:
    int data;
    int height;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data = 0, int h = 0) : data(data), height(h), left(nullptr), right(nullptr) {}

};

int getHeight(TreeNode* &root){
    return root ? root->height : -1;
}

void updateHeight(TreeNode* &root){
    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
}


void insertIntoTree(TreeNode* &root, int val){
    if(root == nullptr){
        root = new TreeNode(val);
        return;
    }
    if(val < root->data){
        root->height += 1;
        insertIntoTree(root->left, val);
    }else if(val > root->data){
        root->height += 1;
        insertIntoTree(root->right, val);
    }else{
        std::cout << "Duplicate valuue!\n";
        return;
    }
    updateHeight(root);
}

void preorder(TreeNode* &root){
    if(root == nullptr){
        return;
    }
    std::cout << "(" << root->data << ", h=" << root->height << ")\n";
    preorder(root->left);
    preorder(root->right);
}


int main(){
    TreeNode* root = nullptr;
    insertIntoTree(root, 40);
    insertIntoTree(root, 20);
    insertIntoTree(root, 10);
    insertIntoTree(root, 60);
    insertIntoTree(root, 50);
    preorder(root);

    delete root;
    return 0;
}