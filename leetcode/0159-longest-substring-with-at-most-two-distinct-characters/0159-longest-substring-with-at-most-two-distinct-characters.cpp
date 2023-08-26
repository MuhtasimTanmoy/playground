class Solution {
    const int LIMIT = 2;
public:
    int lengthOfLongestSubstringTwoDistinct(string s, int res = 0) {
        unordered_map<int, int> tracker;
        for (int i = 0, l = 0; i < s.size(); i++) {
            tracker[s[i]]++;
            while (tracker.size() > LIMIT) {
                if (--tracker[s[l]] == 0) tracker.erase(s[l]);
                l++;
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};