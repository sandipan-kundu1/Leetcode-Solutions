#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) 
            return false;  // If the total number of cards is not divisible by groupSize, we can't form groups
        
        map<int, int> cardCount;
        for (int card : hand) {
            cardCount[card]++;
        }
        
        for (auto it = cardCount.begin(); it != cardCount.end(); ++it) {
            int startCard = it->first;
            int count = it->second;
            if (count > 0) {  // Only process if there are still cards left of this value
                for (int i = 0; i < groupSize; ++i) {
                    if (cardCount[startCard + i] < count) 
                        return false;  // If we don't have enough cards to form a group, return false
                    cardCount[startCard + i] -= count;  // Use up the cards for the group
                }
            }
        }
        
        return true;
    }
};
