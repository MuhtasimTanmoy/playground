/*

If only yes or no ans then this would work

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int idiff, int valdiff) {
        vector<pair<int, int>> dp;
        for (auto i = 0; i < nums.size(); i++) {
            if (dp.empty()) dp.push_back({nums[i], nums[i]});
            else {
                pair<int, int> item = {
                    min(dp.back().first, nums[i]), 
                    max(dp.back().second, nums[i])
                };
                dp.push_back(item);
            }
            if (i - idiff >= 0) {
                if (abs(dp[i - idiff].first - nums[i]) >= valdiff) 
                    return {i, i - idiff};
                if (abs(dp[i - idiff].second - nums[i]) >= valdiff) 
                    return {i, i - idiff};
            }
        }
        return {-1, -1};
    }
*/

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int idiff, int valdiff) {
        map<int, int> m;
        for (int i = idiff; i < nums.size(); ++i) {
            m[nums[i - idiff ]] = i - idiff;
            
            auto it = m.lower_bound(nums[i] + valdiff);
            if (it != end(m)) return {i, it->second };
            
            it = m.upper_bound(nums[i] - valdiff);
            if (it != begin(m)) return {i, prev(it)->second };
        }
        return {-1, -1};
    }
};