class Solution {
public:
    char nextGreatestLetter(vector<char>& ls, char target) {
        auto idx = upper_bound(ls.begin(), ls.end(), target) - ls.begin();
        if (idx == ls.size()) return ls[0];
        return ls[idx];
    }
};