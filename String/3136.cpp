#include <iostream>
#include <string>
using namespace std;

bool validWord(string& word){
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    if(word.size() < 3) return false;
    int vowel = 0, cons = 0;
    for(char i : word){
        if(isalpha(i)){
            if(i == 'a' || i == 'u' || i == 'o' || i == 'e' ||i == 'i'){
                vowel++;
            }else{
                cons++;
            }
        }else if(!isalnum(i)) return false;
    }
    if(vowel > 0 && cons > 0) return true;
    return false;
}

int main(){
    string word;
    cin >> word;

    if(validWord(word)){
        cout << "Valid\n";
    }else{
        cout << "Invalid\n";
    }

    return 0;
}