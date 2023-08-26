class Solution {
public:
    int maxSum(vector<int>& nums) {
        auto get_max_digit = [](int n) {
            int max_digit = 0; 
            while (n) {
                auto digit = n % 10;
                max_digit = max(max_digit, digit);
                n /= 10;
            }
            return max_digit;
        };
        
        int res = -1;
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < nums.size() - 1; i++)
            for (int j = i + 1; j < nums.size(); j++) {
                auto is_same = get_max_digit(nums[i]) == get_max_digit(nums[j]);
                if (is_same) {
                    res = max(res, nums[i] + nums[j]);
                    break;
                }
            }
        return res;
    }
};