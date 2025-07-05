#include <iostream>
#include <unordered_map>

void insertIntoMap(std::unordered_map<int, int> &freq){
    while(1){
        int val;
        int f;
        std::cout << "Enter number (-1 for exit):";
        std::cin >> val;
        if(val == -1) break;
        std::cout << "\nEnter frequency of " << val << " :";
        std::cin >> f;
        // freq.insert({val, f});
        freq[val] = f;
    }   
}

void printMap(std::unordered_map<int, int> &freq){
    for(auto& i : freq){
        std::cout << i.first << " : " << i.second << "\n";
    }
}

int main(){
    std::unordered_map<int, int> freq;
    insertIntoMap(freq);
    std::cout << "\n";
    printMap(freq);

    return 0;
}