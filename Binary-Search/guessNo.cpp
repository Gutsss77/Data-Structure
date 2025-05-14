/*
 Problem: Guess the Number
You are playing a game where you need to guess a secret number between 1 and n.
Each time you guess, you will be told whether the secret number is higher, lower, or equal to your guess.
*/
#include <iostream>
using namespace std;


class GuessingGame {
    int secret;
public:
    GuessingGame(int sec) : secret(sec) {}

    int guess(int num) {
        if (num > secret) return -1;
        else if (num < secret) return 1;
        else return 0;
    }

    int guessNumber(int n) {
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int res = guess(mid);
            if (res == 0) return mid;
            else if (res == -1) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};

int main() {
    int secret = 77;
    int n = 100;
    GuessingGame gg(secret);
    int found = gg.guessNumber(n);
    cout << "The secret number is: " << found << endl;
    return 0;
}