class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> counter(26, 0); int odd_count = 0;
        for (auto c: s) counter[c - 'a']++;
        for (auto c: counter) if (c && (c & 1)) odd_count++;
        return odd_count == (s.size() & 1);
    }
};