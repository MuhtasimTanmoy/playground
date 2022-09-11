class Solution {
public:
    int gcd(int a, int b) {
        while (a % b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return b;
    }
    
    bool isGoodArray(vector<int>& nums) {
        int n = nums.size();
        int a = 0;
        for(int i = 0; i < n; i++) {
            a = gcd(a, nums[i]);
            if (a == 1) return true;
        }
        return false;
    }
};