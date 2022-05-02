class Solution {
public:
    
//     new array
//
//     vector<int> sortArrayByParity(vector<int>& nums) {
//         int n = size(nums);
//         int start = 0 , end = n - 1;\
//         vector<int> ans(n);
//         for(auto x : nums) {
//             if(x & 1 == 0) ans[start++] = x;
//             else ans[end--] = x;
//         }
//         return ans ;
//     }
    
    void swap(int &a, int& b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    
    // in place
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int length = size(nums);
        int start = 0;
        
        for( int i = 0; i < length; i++ ) {
            if ( ( nums[i] & 1 ) == 0) {
                if ( i != start) swap(nums[i], nums[start]);
                start++;
            }
        }
        
        return nums;
        
    }
};