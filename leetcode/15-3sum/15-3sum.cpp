class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size() - 2; i++) {
            if (i && nums[i] == nums[i-1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                auto sum = nums[left] + nums[right] + nums[i];
                if (sum == 0) {
                    res.push_back( {nums[i], nums[left++], nums[right--]} );
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if ( sum > 0 ) right--;
                else left++;
            }
        }
        return res;
    }
};

// [-4, -1, -1, 0, 1, 2]