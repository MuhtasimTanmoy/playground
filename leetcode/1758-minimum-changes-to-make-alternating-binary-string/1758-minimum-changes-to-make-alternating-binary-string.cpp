class Solution {
public:
    int minOperations(string s) {
        auto go = [&](char start) {
            int diff = 0;
            for (auto c: s) {
                if (c == start) diff++;
                start = start == '0' ? '1': '0';
            }
            return diff; 
        };
        return min(go('0'), go('1'));
    }
};