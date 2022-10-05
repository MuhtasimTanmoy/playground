class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left = 0, right = 0, res = 0;
        unordered_map<char, int> bag;
        while (right < s.size()) {
            bag[s[right++]]++;
            while (bag.size() > 2) {
                bag[s[left]]--;
                if (!bag[s[left]]) bag.erase(s[left]);
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};