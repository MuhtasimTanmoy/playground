class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        unordered_set<char> bag;
        int left = 0, right = 0;
        
        while (right < s.size()) {
            auto curr = s[right++];
            while (bag.count(curr)) bag.erase(s[left++]);
            bag.insert(curr);
            
            longest = max(longest, right -left);
        }
        return longest;
    }
};