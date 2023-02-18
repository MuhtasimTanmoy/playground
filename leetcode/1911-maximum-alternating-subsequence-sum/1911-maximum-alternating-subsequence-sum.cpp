class Solution {
public:
//     long long maxAlternatingSum(vector<int>& nums) {
//         unordered_map<string, int> cache;
//         auto key = [](int i, bool b, int s) {
//             return to_string(i) + "-" + to_string(b) + "-" + to_string(s);
//         };
        
//         function<int(int, bool, int)> go = [&](auto idx, auto isMinus, auto sum) {
//             if (idx == nums.size()) return sum;
//             auto k = key(idx, isMinus, sum);
//             if (cache.count(k)) return cache[k];
            
//             auto res = go(idx + 1, !isMinus, sum + (isMinus ? -nums[idx]: nums[idx]));
//             res = max(res, go(idx + 1, true, nums[idx]));
//             return cache[k] = max(res, go(idx + 1, isMinus, sum));
//         };
//         return go(0, false, 0);
//     }
    
    long long maxAlternatingSum(vector<int>& A) {
        long res = A[0];
        for (int i = 1; i < A.size(); ++i) res += max(A[i] - A[i-1], 0);
        return res;
    }
};