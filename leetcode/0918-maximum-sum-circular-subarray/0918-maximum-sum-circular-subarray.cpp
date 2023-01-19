class Solution {
public:
//     int maxSubarraySumCircular(vector<int>& nums) {
//         int sum = 0, maxSum = 0, currMax = nums[0], minSum = 0, currMin = nums[0];
//         for (auto num: nums) {
//             currMax = max(currMax, 0) + num;
//             maxSum = max(currMax, maxSum);
//             currMin = min(currMin, 0) + num;
//             minSum = min(currMin, minSum);
//             sum += num;
//         }
//         return maxSum > 0 ? max(maxSum, sum - minSum) : maxSum;
//     }
    
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
        for (int& a : A) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};