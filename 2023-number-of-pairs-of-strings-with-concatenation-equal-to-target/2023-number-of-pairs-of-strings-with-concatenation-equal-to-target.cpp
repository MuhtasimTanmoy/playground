class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int count = 0;
        for (int i = 0; i < nums.size() ; i++) 
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                if (nums[i].size() + nums[j].size() != target.size()) continue;
                auto concat = nums[i] + nums[j];
                if (concat == target) count++;
            }
        return count;
    }
};