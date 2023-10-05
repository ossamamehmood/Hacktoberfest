#include <string>

using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int countA = 0;
        int countB = 0;
        
        for (int i = 1; i < colors.length() - 1; i++) {
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
                if (colors[i] == 'A') {
                    countA++; 
                } else {
                    countB++;
                }
            }
        }
        
        return countA > countB;
    }
};