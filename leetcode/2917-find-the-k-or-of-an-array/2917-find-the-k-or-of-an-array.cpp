class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        vector<int> set_bits(32, 0);
        for (auto num: nums) 
            for (auto i = 0; i < 32; i++)
                if (num & (1 << i))
                    set_bits[i]++;
        int res = 0;
        for (auto i = 0; i < 32; i++)
            if (set_bits[i] >= k)
                res += (1 << i);
        return res;
    }
};