// class Solution {
// public:
//     long long minCost(vector<int>& nums, vector<int>& cost) {
        
//         int up = 1000000, down = 1;
//         // for (auto num: nums)
//         //     up = max(up, num), down = min(down, num);
        
//         auto get_cost = [&](int target) {
//             int diff = 0;
//             for (int i = 0; i < nums.size(); i++) 
//                 diff += abs(nums[i] - target) * cost[i];
//             return diff / nums.size();
//         };
        
//         int res = INT_MAX;
//         while (down < up) {
//             auto m = (down + up) / 2;
//             auto l = get_cost(m), r = get_cost(m + 1);
//             res = min(l, r);
//             if (l < r) up = m; else down = m + 1;
//         }
        
//         return res;
//     }
// };


class Solution {
public:
    long long minCost(vector<int>& A, vector<int>& cost) {
        long long l = 1, r = 1000000, res = INT_MAX, x;
        while (l < r) {
            x = (l + r) / 2;
            long long y1 = f(A, cost, x), y2 = f(A, cost, x + 1);
            res = min(y1, y2);
            if (y1 < y2) r = x;
            else l = x + 1;
        }
        return res;
    }

    long long f(vector<int>& A, vector<int>& cost, int x) {
        long long res = 0;
        for (int i = 0; i < A.size(); ++i)
            res += 1L * abs(A[i] - x) * cost[i];
        return res;
    }
};