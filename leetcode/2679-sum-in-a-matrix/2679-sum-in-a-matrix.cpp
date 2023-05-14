class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (auto &num: nums) sort(num.begin(), num.end());
        
        int res = 0;
        for (int i = 0; i < nums[0].size(); i++) {
            int max_num = 0;
            for (int j = 0; j < nums.size(); j++)
                max_num = max(max_num, nums[j][i]);
            res += max_num;
        }
        return res;
    }
};