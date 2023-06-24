class Solution {
public:
    bool isFascinating(int n) {
        auto l = n * 2, r = n * 3;
        auto str = to_string(n) + to_string(l) + to_string(r);
        unordered_set<char> bag(str.begin(), str.end());
        return !bag.count('0') && bag.size() == 9 && str.size() == 9;
    }
};