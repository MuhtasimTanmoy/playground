class Solution {
public:
    int maxScore(string s) {
        int totalzeroCount = 0;
        for (auto c: s) 
            if (c == '0') totalzeroCount++;
        int res = 0, currZero = 0, currentOne = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') currZero++; else currentOne++;
            int total = currZero + (s.size() - totalzeroCount - currentOne);
            res = max(res, total);
        }
        return res;
    }
};