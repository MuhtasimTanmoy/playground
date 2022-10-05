class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd, even;
        int length = size(nums);
        for(int i = 0; i < length; i++) 
            (i & 1) ? odd.push_back(nums[i]) : even.push_back(nums[i]);
        
        sort(begin(even), end(even));
        sort(begin(odd), end(odd), greater<int>());
        
        int io = 0;
        int ie = 0;
        int start = 0;
        
        while( start < length ) {
            if ( (start & 1) ) nums[start++] = odd[io++];
            else nums[start++] = even[ie++];
        }
        return nums;
    }
};