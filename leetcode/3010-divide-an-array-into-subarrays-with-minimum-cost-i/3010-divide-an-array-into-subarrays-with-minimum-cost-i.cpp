class Solution {
public:
    int minimumCost(vector<int>& nums) {
        auto res = nums.front();
        int one = INT_MAX, two = INT_MAX;
        for (auto i = 1; i < nums.size(); i++) 
            if (nums[i] <= one)
                two = one, one = nums[i];
            else if (nums[i] < two)
                two = nums[i];
        return res + one + two;
    }
};