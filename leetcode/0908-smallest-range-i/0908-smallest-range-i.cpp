class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        if (nums.size() == 1) return 0;
        auto minElem = *min_element(nums.begin(), nums.end());
        auto maxElem = *max_element(nums.begin(), nums.end());
        return max(maxElem - minElem - 2 * k, 0);
    }
};