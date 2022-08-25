class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_set<char> flush(suits.begin(), suits.end());
        if (flush.size() == 1) return "Flush";
        vector<int> counter(14, 0);
        int maxCount = 0;
        for (auto rank: ranks) {
            counter[rank]++;
            maxCount = max(counter[rank], maxCount);
        }
        if (maxCount >= 3) return "Three of a Kind";
        else if (maxCount == 2) return "Pair";
        else return "High Card";
    }
};