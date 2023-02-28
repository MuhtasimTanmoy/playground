class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        auto n = nums.size();
        unordered_map<int, int> um;
        vector<int> res;
        for (int i = 0; i < k; i++) um[nums[i]]++;
        res.push_back(um.size());
        
        for (int i = k; i < n; i++) {
            um[nums[i]]++;
            if (--um[nums[i - k]] == 0) um.erase(nums[i - k]);
            res.push_back(um.size());
        }
        return res;
    }
};