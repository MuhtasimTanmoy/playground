class Solution {
    int residue = 1e9 + 7;
public:
    int countNicePairs(vector<int>& nums) {
        auto rev = [](int num) {
            int res = 0;
            while (num) res = res * 10 + num % 10, num /= 10;
            return res;
        };
        unordered_map<int, int> cache;
        vector<int> rnums(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) 
            rnums[i] = rev(nums[i]);
        
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto key = nums[i] - rnums[i];
            res = (res + cache[key]) % residue;
            cache[key]++;
        }  
        return res;
    }
};