class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_set<int> bag;
        
        vector<int> post(nums.size() + 1);
        for (int i = nums.size() - 1; i >= 0; i--) {
            bag.insert(nums[i]);
            post[i] = bag.size();
        }
                
        bag.clear();
        vector<int> res;
        for (auto i = 0; i < nums.size(); i++) {
            bag.insert(nums[i]);
            res.push_back(bag.size() - post[i+1]);
        }
        return res;
    }
};