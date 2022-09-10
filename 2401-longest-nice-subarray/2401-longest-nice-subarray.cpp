/*

positive integers

length of the longest nice subarray

bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0

*/

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 1;
        for (int i = 0; i < nums.size(); i++) {
            int orResult = nums[i];
            for (int j = i + 1; j < nums.size(); j++)
                if ( (orResult & nums[j]) == 0 ) {
                    orResult |= nums[j];
                    res = max(res, j - i + 1);
                } else break;
        }
        return res;
    }
};