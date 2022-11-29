class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> counter(26, 0);
        for (auto word: words) 
            for (auto c: word) counter[c-'a']++;
        for (auto c: counter) 
            if (c % words.size() != 0) return false;
        return true;
    }
};