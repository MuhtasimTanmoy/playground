class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> counter(26, 0);
        for (auto c: word1) counter[c - 'a']++;
        for (auto c: word2) counter[c - 'a']--;
        for (auto count: counter) if (abs(count) > 3) return false;
        return true;
    }
};