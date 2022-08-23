// This wont work in case of equal difference input
// class Solution {
// public:
//     int minDifference(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int left = 0, right = nums.size() - 1;
//         if (right <= 3) return 0;
//         int res = 0;
//         int moves = 3;
//         while (moves--) {
//             auto leftDistance = nums[left+1] - nums[left];
//             auto rightDistance = nums[right] - nums[right-1];
//             if (leftDistance >= rightDistance) left++;
//             else right--;
//         }
//         return nums[right] - nums[left];
//     }
// };


class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        function<int(int, int, int)> dfs = 
            [&](int left, int right, int k) -> int {
            if (left >= right) return 0;
            if (!k) return nums[right] - nums[left];
            return min(dfs(left, right - 1, k - 1), dfs(left + 1, right, k - 1));
        };
        return dfs(0, nums.size() - 1, 3);
    }
};