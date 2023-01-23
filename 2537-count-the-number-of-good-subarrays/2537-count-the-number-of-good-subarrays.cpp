class Solution {
public:
    
    // long long countGood(vector<int>& nums, int k, int res = 0) {
    //     unordered_map<int, pair<int, int>> dp;
    //     for (int i = 0; i < nums.size(); i++) {
    //         auto e = nums[i];
    //         if (dp.count(e)) {
    //             dp[e].first += ++dp[e].second; 
    //             cout<<dp[e].first<<endl;
    //         }else dp[e] = {0, 0};
    //         if (dp[e].first >= k) res++;
    //     }
    //     return res;
    // }
    
    long long countGood(vector<int>& nums, int k, long long res = 0) {
        unordered_map<int, int> dp;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            k -= dp[nums[j]]++;
            while ( k <= 0 ) k += --dp[nums[i++]];
            res += i;
        }
        return res;
    }
};