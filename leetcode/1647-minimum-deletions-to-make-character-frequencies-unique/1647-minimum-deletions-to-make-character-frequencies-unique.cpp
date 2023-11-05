class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (auto c: s) freq[c - 'a']++;
        
        int res = 0;
        unordered_set<int> bag;
        for (auto c: freq) {
            while (c && bag.count(c)) c--, res++;
            if (c) bag.insert(c);
        }
        return res;
    }
};