// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int left = 0, right = nums.size() - 1;
//         while (left <= right) {
//             auto mid = left + (right-left) / 2;
//             if (nums[mid] == target) return mid;
//             else if (nums[mid] < target) left = mid + 1;
//             else right = mid - 1;
//         }
//         return left;
//     }
// };


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            auto m = (l + r) >> 1;
            if (nums[m] == target) return m;
            if (nums[m] > target) r = m - 1; else l = m + 1;
        }
        return l;
    }
};