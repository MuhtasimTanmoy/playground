class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> dp;
        for (int i = 0; i < nums.size(); i++) dp[nums[i]].push_back(i);
        
        int dist = INT_MAX;
        for (auto [num, ids]: dp) {
            int local = 0;
            ids.push_back(ids.front() + nums.size());
            for (int i = 1; i < ids.size(); i++)
                local = max(local, (ids[i] - ids[i-1]) / 2);
            dist = min(dist, local);
        }
        return dist;
    }
};