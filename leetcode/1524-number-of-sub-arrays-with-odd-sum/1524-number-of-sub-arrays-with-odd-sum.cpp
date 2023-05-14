class Solution {
    const int MOD = 1e9 + 7;
public:
    int numOfSubarrays(vector<int>& arr) {
        long long even = 0, pre = 0, res = 0;
        for (int i = 0; i < arr.size(); i++) {
            even += !(pre & 1);
            pre += arr[i];
            auto is_odd = pre & 1;
            res = (res + (is_odd ? even: i + 1 - even)) % MOD;
        }
        return res;
    }
};