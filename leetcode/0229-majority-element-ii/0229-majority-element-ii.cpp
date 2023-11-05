class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        auto target = nums.size() / 3;
        sort(nums.begin(), nums.end());
        
        vector<int> res;
        if (!target) res.push_back(nums.front());
        
        for (auto i = 1, count = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) count++; else count = 1;
            if (count > target) 
                if (res.empty() || res.back() != nums[i]) 
                    res.push_back(nums[i]);
        }
        return res;
    }
};