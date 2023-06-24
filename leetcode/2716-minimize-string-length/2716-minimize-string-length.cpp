class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> bag(s.begin(), s.end());
        return bag.size();
    }
};