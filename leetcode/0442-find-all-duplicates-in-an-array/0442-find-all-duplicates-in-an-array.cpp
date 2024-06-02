class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> res;
        for (auto i = 0; i < nums.size(); i++) {
            auto index = abs(nums[i]);
            if (!index) continue;
            
            index--;
            
            if (nums[index] < 0) {
                if (res.count(nums[index])) 
                    nums[index] = 0, res.erase(index + 1);
                else res.insert(index + 1);
            } else nums[index] = -nums[index];
        }
        return vector<int>(res.begin(), res.end());
    }
};