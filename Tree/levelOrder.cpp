#include <cstddef>
#include <iostream>
#include <queue>

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

void insertInTree(Node* &root){
    int data;
    std::cout << "Enter data : ";
    std::cin >> data;
    
    if(data == -1){
        return;
    }

    root = new Node(data);

    std::cout << "Left of " << data << std::endl;
    insertInTree(root->left);
    std::cout << "Right of" << data << std::endl;
    insertInTree(root->right);

}

void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        std::cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}


int main(){
    Node* root;
    insertInTree(root);
    levelOrderTraversal(root);

    return 0;
}