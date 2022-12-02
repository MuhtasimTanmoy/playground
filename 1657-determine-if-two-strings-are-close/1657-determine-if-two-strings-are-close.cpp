class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> word1Map(26, 0);
        vector<int> word2Map(26, 0);
        for (auto c : word1)  word1Map[c - 'a']++;
        for (auto c : word2) word2Map[c - 'a']++;
        for (int i = 0; i < 26; i++) 
            if ((!word1Map[i] && word2Map[i]) ||
                (!word2Map[i] && word1Map[i])) 
                return false;
        sort(word1Map.begin(), word1Map.end());
        sort(word2Map.begin(), word2Map.end());
        return word1Map == word2Map;
    }
};