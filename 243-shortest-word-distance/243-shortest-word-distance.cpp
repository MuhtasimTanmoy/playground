class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int word1_idx = -1, word2_idx = -1;
        int index = 0, res = INT_MAX;
        for (auto word: wordsDict) {
            if (word == word1) word1_idx = index;
            else if (word == word2) word2_idx = index;
            if (word1_idx != -1 && word2_idx != -1) res = min(res, abs(word1_idx - word2_idx));
            index++;    
        }
        return res;
    }
};