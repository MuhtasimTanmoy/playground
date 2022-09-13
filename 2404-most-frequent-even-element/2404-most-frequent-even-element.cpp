class Solution {
    public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> m;
        int max_cnt = 0, res = INT_MAX;
        for (int n : nums)
            if (n % 2 == 0)
                if (int cnt = ++m[n]; cnt >= max_cnt) {
                    res = max_cnt < cnt ? n : min(res, n);
                    max_cnt = cnt;
                }
        return res == INT_MAX ? -1 : res;
    }
};