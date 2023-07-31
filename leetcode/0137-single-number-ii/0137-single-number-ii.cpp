class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0);
        
        for (auto num: nums) 
            for (int i = 0; i < 32; i++) 
                if (num & (1 << i)) bits[i]++;
        
        int res = 0;
        for (int i = 0; i < 32; i++) 
            if (bits[i] % 3 == 1) res += (1 << i);
        return res;
    }
};