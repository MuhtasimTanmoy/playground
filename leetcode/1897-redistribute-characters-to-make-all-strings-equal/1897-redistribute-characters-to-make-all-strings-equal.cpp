class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> counter(26, 0);
        int n = words.size();
        for (auto word: words)
            for (auto c: word)
                counter[c - 'a']++;
        for (auto count: counter)
            if (count % n != 0)
                return false;
        return true;
    }
};