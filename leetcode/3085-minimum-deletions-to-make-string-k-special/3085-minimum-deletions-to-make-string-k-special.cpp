class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> count(26, 0); int ans = INT_MAX;
        for (auto c: word) count[c - 'a']++;
        for (auto c: count) {
            int cur = 0;
            for (auto now: count) 
                cur += now < c ? now: max(0, now - c - k);
            ans = min(ans, cur);
        }
        return ans;
    }
};