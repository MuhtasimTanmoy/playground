class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> dp {0};
        for (auto a: arr) dp.push_back(dp.back() ^ a);
        
        int n = dp.size(), res = 0;
        for (auto l = 0; l < n; l++)
            for (auto r = l + 1; r < n; r++) 
                if (dp[r] == dp[l])
                    res += r - l - 1;
        return res;
    }
};