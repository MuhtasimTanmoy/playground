class Solution {
public:
    int minDeletions(string s) {
        vector<int> charMap(26, 0);
        for(auto c: s) charMap[c - 'a']++;
        
        int res = 0;
        unordered_set<int> count;
        for(auto &charCount: charMap) {
            while (count.count(charCount)) {
                charCount--;
                if(!charCount) count.erase(charCount);
                res++;
            }
            if (charCount) count.insert(charCount);
        }
        return res;
    }
};