class Solution {
public:
    long long minimumReplacement(vector<int>& A) {
//         long long res = 0, n = nums.size();
//         for (int i = n - 1; i > 0; i--) {
//             auto left = nums[i - 1], right = nums[i];
//             if (left > right) {
//                 auto to_add = (left - 1 ) / right, rem = left % right;
//                 while (rem && 2 * (rem + 1) <= right) right -= to_add, rem++;
//                 res += to_add;
//                 nums[i - 1] = (left % right) ? rem: right;
//             }
//         }
//         for (auto c: nums) cout<<c<<endl;
//         return res;
        
        long x = 1000000000, res = 0, k;
        for (int i = A.size() - 1; i >= 0; --i) 
            k = (A[i] + x - 1) / x,
            x = A[i] / k,
            res += k - 1;
        return res;
    }
};