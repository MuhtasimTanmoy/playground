class Solution {
public:
    int minOperations(vector<int>& A, int target) {
        long long tot = accumulate(A.begin(), A.end(), 0L), res = 0;
        if (tot < target)
            return -1;
        sort(A.begin(), A.end());
        while (target > 0) {
            int a = A.back(); A.pop_back();
            if (tot - a >= target) tot -= a;
            else if (a <= target)  tot -= a, target -= a;
            else A.push_back(a / 2), A.push_back(a / 2), res += 1;
        }
        return res;
    }
};