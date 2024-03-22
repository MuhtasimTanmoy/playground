class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 0;
        for (auto num: nums) 
            l = max(l, num),
            r += num;
        
        auto can = [&](int target, int left) {
            int sum = 0;
            for (auto num: nums) {
                sum += num;
                if (sum > target) {
                    if (--left <= 0) return false;
                    sum = num;
                } 
            }
            return left >= 1;
        };
                
        while (l < r) {
            auto can_be = l + (r - l) / 2;            
            if (can(can_be, k)) r = can_be; else l = can_be + 1;
        }
        return r;
    }
};