class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        long long ans = 0, prefix = 0; 
        for (auto& x : nums) {
            prefix += x; 
            ans |= x | prefix; 
        }
        return ans; 
    }
};