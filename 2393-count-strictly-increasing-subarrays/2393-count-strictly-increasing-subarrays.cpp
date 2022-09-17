class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        long long count = nums.size(); int cnt = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] < nums[i + 1]) cnt++; else cnt = 0;
            count += cnt;
        }
        return count;
    }
};