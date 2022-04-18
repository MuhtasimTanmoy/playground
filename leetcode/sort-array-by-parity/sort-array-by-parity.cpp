class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = size(nums);
        int start = 0 , end = n - 1;
        vector<int> ans(n);
        
        for(auto x : nums) {
            if(x % 2 == 0) ans[start ++] = x;
            else ans[end--] = x;
        }
        return ans ;
    }
};