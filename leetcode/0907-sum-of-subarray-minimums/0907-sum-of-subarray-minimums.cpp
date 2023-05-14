class Solution {
    const int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr, long long res = 0) {
        arr.push_back(0);
        vector<int> stk;
        for (int i = 0; i < arr.size(); i++) {
            while (stk.size() && arr[stk.back()] > arr[i]) {
                auto r = stk.back(); stk.pop_back();
                auto l_range = r - (stk.size() ? stk.back(): -1),
                     r_range = i - r;
                res = (res + 1LL * l_range * arr[r] * r_range) % MOD;
            }
            stk.push_back(i);
        }
        return res;
    }
};

// class Solution {
//     const int MOD = 1e9 + 7;
// public:
//     int sumSubarrayMins(vector<int>& arr, long long res = 0) {
//         arr.push_back(0);
        
//         vector<int> stk;
//         for (int i = 0; i < arr.size(); i++) {
//             while (stk.size() && arr[i] < arr[stk.back()]) {
//                 auto m = stk.back();
//                 auto min_in = arr[m]; stk.pop_back();
//                 auto l_range = m - (stk.size() ? stk.back(): -1), 
//                      r_range = i - m;
//                 res = (res + 1ll* min_in * l_range * r_range) % MOD;
//             }
//             stk.push_back(i);
//         }
//         return res;
//     }
// };