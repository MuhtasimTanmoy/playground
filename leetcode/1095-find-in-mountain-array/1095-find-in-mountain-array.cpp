/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &nums) {
        auto peak = [&]() {
            int l = 0, r = nums.length(), n = nums.length();
            while (l <= r) {
                auto m = (r + l) / 2;
                auto is_left_less = m > 0 ? nums.get(m - 1) < nums.get(m) : true,
                     is_right_less = m < (n - 1) ? nums.get(m + 1) < nums.get(m) : true;
                if (is_left_less && is_right_less) return m;
                else if (is_left_less) l = m + 1; else r = m - 1;
            }
            throw "error";
        };
        
        auto p = peak();
        auto search = [&](int l, int r, bool dir) {
            while (l <= r) {
                auto m = (l + r) / 2;
                if (nums.get(m) == target) return m;
                else if (target > nums.get(m) == dir) l = m + 1;
                else r = m - 1;
            }
            return -1;
        };
        
        auto l = search(0, p, true);
        if (l != -1) return l;
        return search(p, nums.length() - 1, false);
    }
};