class Solution {
public:
    int maxSubArray(vector<int>& N) {
        int sum = 0, res = INT_MIN;
        for (auto n: N) 
            sum = max(n, sum + n), res = max(res, sum);
        return res;
    }
};