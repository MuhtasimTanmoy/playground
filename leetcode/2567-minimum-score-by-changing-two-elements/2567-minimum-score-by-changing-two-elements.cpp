class Solution {
//     int minimize(deque<int>& nums) {
//         if (nums.size() <= 3) return 0;
            
//         int count = 2;
//         int l = 0, r = nums.size() - 2;
//         while (count--) {
//             auto ldis = nums[l] - nums[l-1];
//             auto rdis = nums[r+1] - nums[r];
//             if (ldis == rdis) {
//                 nums.pop_back();
//                 nums.pop_front();
//                 return minimize(nums);
//             }
//             if (ldis < rdis) l++; else if (ldis > rdis) r--;
//         }
        
//         int res = 0;
//         for (auto i = l; i < r; i++) res = max(res, abs(nums[l] - nums[r]));
//         return res;
//     }
public:
    int minimizeSum(vector<int>& n) {
        int len = n.size() - 1;
        sort(n.begin(), n.end());
        return min ({
            n[len-1] - n[1],
            n[len-2] - n[0],
            n[len] - n[2]
        });
    }
};