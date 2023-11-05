class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, 
                                                vector<string>& words, 
                                                vector<int>& groups) {
        vector<string> res {words.front()};
        int last = groups.front();
        for (int i = 1; i < n; i++) 
            if (last != groups[i]) 
                res.push_back(words[i]), last = groups[i];
        return res;
    }
};