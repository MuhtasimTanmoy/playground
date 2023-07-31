class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long n = nums.size(), res = nums.back();
        for (long long i = n - 2, r = nums.back(); i >= 0; i--) 
            r =  nums[i] +  (nums[i] <= r ? r: 0),
            res = max(res, r);
        return (long long) res;
    }
};