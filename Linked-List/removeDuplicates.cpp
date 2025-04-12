#include<iostream>
#include<set>

//This function helps in removing the duplicates from list which is defined globally
//for normal list provide address, use;
/*
void removeDuplicate(Node* &head) define the parameter for reference;
*/
void removeDuplicate(){
    set<int> seen;
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (seen.count(curr->data)) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
}