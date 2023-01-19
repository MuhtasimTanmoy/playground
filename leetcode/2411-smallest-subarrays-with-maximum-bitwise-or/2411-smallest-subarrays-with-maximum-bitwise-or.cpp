class Solution {
public:
    // vector<int> smallestSubarrays(vector<int>& nums) {
    //     vector<int> res(nums.size(), 0);
    //     for (int i = 0; i < nums.size(); i++) {
    //         int countingMax = 0, localMax = 0, localRes = 0;
    //         for (int j = i; j < nums.size(); j++) {
    //             countingMax ^= nums[j];
    //             if (countingMax > localMax) {
    //                 localMax = countingMax;
    //                 localRes = j - i + 1;
    //             }
    //         } 
    //         res[i] = localRes;
    //     }
    //     return res;
    // }
    
    vector<int> smallestSubarrays(vector<int>& A) {
        int last[30] = {}, n = A.size();
        vector<int> res(n, 1);
        for (int i = n - 1; i >= 0; --i) 
            for (int j = 0; j < 30; ++j) {
                if (A[i] & (1 << j))
                    last[j] = i;
                res[i] = max(res[i], last[j] - i + 1);
            }
        return res;
    }
};


