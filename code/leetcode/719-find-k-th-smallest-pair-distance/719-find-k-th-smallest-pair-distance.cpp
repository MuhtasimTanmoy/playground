class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        auto ok = [&](int target) -> bool {
            int total = 0;
            int l = 0;
            for(int r = 0 ; r < size(nums); r++) {
                while(l < r && nums[r] - nums[l] > target) l++;
                total += (r-l);
            }
            return total >= k;
        };
        
        int left = 0, right = nums.back() - nums[0], ans = -1;
        while(left <= right) {
            auto mid = left + (right-left)/2;
            if (ok(mid)) {
                ans = mid;
                right = mid - 1;
            } else 
                left = mid + 1;
        }
        return ans;
    }
};