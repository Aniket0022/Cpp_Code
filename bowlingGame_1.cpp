#include <iostream>
#include <vector>
using namespace std;

int computeBowlingScore(const vector<int>& pinFalls) {
    int totalPoints = 0;
    int currentRoll = 0;
    int size = pinFalls.size();

    for (int turn = 0; turn < 10; ++turn) {
        if (currentRoll >= size) break;

        if (pinFalls[currentRoll] == 10) {
            if (currentRoll + 2 < size)
                totalPoints += 10 + pinFalls[currentRoll + 1] + pinFalls[currentRoll + 2];
            else
                totalPoints += 10; 
            currentRoll += 1;
        }
        else if (currentRoll + 1 < size && pinFalls[currentRoll] + pinFalls[currentRoll + 1] == 10) {
            if (currentRoll + 2 < size)
                totalPoints += 10 + pinFalls[currentRoll + 2];
            else
                totalPoints += 10;
            currentRoll += 2;
        }
        else if (currentRoll + 1 < size) {
            totalPoints += pinFalls[currentRoll] + pinFalls[currentRoll + 1];
            currentRoll += 2;
        }
        else {
            break; 
        }
    }

    return totalPoints;
}

int main() {
   
    vector<int> gameRolls = {1, 5, 0, 4, 6, 5, 10, 4, 6, 9, 1, 10, 3, 4, 2, 1, 0, 0};

    int finalScore = computeBowlingScore(gameRolls);
    cout << "Final Score: " << finalScore << endl;

    return 0;
}