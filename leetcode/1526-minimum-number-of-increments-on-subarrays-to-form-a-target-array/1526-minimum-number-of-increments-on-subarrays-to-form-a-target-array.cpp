class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int prev = 0, res = 0;
        for (auto now: target) 
            res += max(now - prev, 0),
            prev = now;
        return res;
    }
};