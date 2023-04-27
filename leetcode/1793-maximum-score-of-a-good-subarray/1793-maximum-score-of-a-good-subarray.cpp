// Gets TLE
/*
class Solution {
public:
    int maximumScore(vector<int>& nums, int k, int res = INT_MIN) {
        for (int i = 0; i < nums.size(); i++) {
            int min_in_range = INT_MAX;
            for (int j = i; j < nums.size(); j++) {
                min_in_range = min(min_in_range, nums[j]);
                if (i <= k && j >= k) 
                    res = max(res, min_in_range * (j - i + 1));
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int min_elem = nums[k], l = k - 1, r = k + 1, cnt = 1, len = nums.size(), res = min_elem;
        
        while (l >= 0 && r < len) {
            auto left = nums[l], right = nums[r];
            min_elem = min(min_elem, right > left ? nums[r++]: nums[l--]);
            cnt++;
            res = max(res, min_elem * cnt);
        }
        
        while (l >= 0) 
            min_elem = min(min_elem, nums[l--]), cnt++, res = max(res, min_elem * cnt);
        
        while (r < len)
            min_elem = min(min_elem, nums[r++]), cnt++, res = max(res, min_elem * cnt);
        
        return res;
    }
};