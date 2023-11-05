class Solution {
public:
    long long minSum(vector<int>& l, vector<int>& r) {
        long long sum_l = 0, sum_r = 0, zero_l = 0, zero_r = 0;
        for (auto i: l) if (i) sum_l += i; else zero_l++;
        for (auto i: r) if (i) sum_r += i; else zero_r++;
        
        if (sum_l < sum_r || (sum_l == sum_r && zero_l > zero_r)) 
            swap(sum_l, sum_r), swap(zero_l, zero_r);
        
        auto need = sum_l - sum_r;
        if (need && !zero_r) return -1;
        else if (need < zero_r && !zero_l) return -1;
        
        return max(sum_l + zero_l, sum_r + zero_r);
    }
};