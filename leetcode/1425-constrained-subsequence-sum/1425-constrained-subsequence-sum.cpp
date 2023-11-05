/*

20 / 36 test cases passed

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            auto now = dp[i];
            for (int j = max(0, i - k); j < i; j++) 
                dp[i] = max(dp[i], now + dp[j]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
*/

class Solution {
public:
    typedef pair<int, int> P;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> t(nums.begin(), nums.end());
        
        priority_queue<P, vector<P>> pq;
        pq.push({t.front(), 0});
        
        int maxR = t.front();
        for (int i = 1; i < n; i++) {
            while (pq.size() && pq.top().second < i - k) pq.pop();
            t[i] = max(t[i], nums[i] + pq.top().first);
            pq.push({t[i], i});
            maxR = max(maxR, t[i]);
        }
        return maxR;
    }
};

