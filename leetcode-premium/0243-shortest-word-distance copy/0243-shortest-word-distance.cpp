class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2, 
                         int res = INT_MAX) {
        for (int i = 0, l = -1, r = -1; i < wordsDict.size(); i++) {
            auto word = wordsDict[i];
            if (word == word1) l = i; else if (word == word2) r = i;
            if (l != -1 && r != -1) {
                res = min(res, abs(l - r));
                if (res == 1) return res;
            }
        }
        return res;
    }
};