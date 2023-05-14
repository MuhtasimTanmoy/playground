class Solution {
public:
    double average(vector<int>& salary) {
        int mins = INT_MAX, maxs = INT_MIN, res = 0;
        for (auto s: salary)
            mins = min(s, mins),
            maxs = max(maxs, s),
            res += s;
        double s = res - mins - maxs;
        double n = size(salary) - 2;
        return s / n;
    }
};