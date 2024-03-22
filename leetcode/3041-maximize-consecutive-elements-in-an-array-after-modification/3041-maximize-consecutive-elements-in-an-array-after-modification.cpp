class Solution {
public:
//     int maxSelectedElements(vector<int>& nums, int res = 0) {
//         sort(nums.begin(), nums.end());
//         for (auto num: nums) cout<<num<<" ";
//         vector<int> stk;
//         for (auto num: nums) {
//             if (stk.empty()) stk.push_back(num);
//             else {
//                 auto target = stk.back() + 1;
//                 if (target == num || target == num + 1) stk.push_back(target);
//                 else if (num < target) {}
//                 else {
//                     if (stk.size() == 1 && stk.back() + 2 == num) {}
//                     else stk.clear();
//                     stk.push_back(num);
//                 }
//             }
//             res = max(res, (int) stk.size());
//         }
//         return res;
//     }
    
    int maxSelectedElements(vector<int>& A) {
        unordered_map<int, int> dp;
        sort(A.begin(), A.end());
        int res = 0;
        for (int& a : A) 
            res = max(res, dp[a + 1] = dp[a] + 1),
            res = max(res, dp[a] = dp[a - 1] + 1);
        return res;
    }
};

// 2 3 6 8 9 10 10 11 12 12 13 16 18 19 