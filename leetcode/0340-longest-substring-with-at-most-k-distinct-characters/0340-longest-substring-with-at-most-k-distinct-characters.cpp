class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<int, int> tracker; int res = 0;
        for (int i = 0, l = 0; i < s.size(); i++) {
            tracker[s[i]]++;
            while (tracker.size() > k) {
                if (--tracker[s[l]] == 0) tracker.erase(s[l]);
                l++;
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};