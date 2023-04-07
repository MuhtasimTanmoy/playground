class Solution {
    const int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        arr.push_back(0);
        vector<int> stk;
        long long res = 0;
        for (int i = 0; i < arr.size(); i++) {
            while (stk.size() && arr[i] < arr[stk.back()]) {
                auto mid_index = stk.back();
                auto min_in = arr[mid_index]; stk.pop_back();
                auto l_range = mid_index - (stk.size() ? stk.back(): -1), 
                     r_range = i - mid_index;
                res = (res + 1ll* min_in * l_range * r_range) % MOD;
            }
            stk.push_back(i);
        }
        return res;
    }
};