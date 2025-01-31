class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0, one_count = 0;
        for (auto c: s) 
            if (c == '1') one_count++; else res += one_count;
        return res;
    }
};