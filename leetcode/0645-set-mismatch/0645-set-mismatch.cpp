// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int missing = 1, dup = -1;
//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] == nums[i-1]) dup = nums[i];
//             else if (nums[i] != i) missing = i;
//         }
//         return {dup, missing};
//     }
// };


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = -1;
        int missing = -1;
        for (int i = 0; i<n; i++) {
            int num = abs(nums[i]);
            if (nums[num-1] < 0) dup = num;
            else nums[num-1] *= (-1);
        }
        for (int i = 0; i<n; i++)
            if (nums[i] > 0) {
                missing = i + 1;
                break;
            }
        return {dup, missing};
    }
};

// [3,2,3,4,6,5]
// [2,3,4,4,5,6]
