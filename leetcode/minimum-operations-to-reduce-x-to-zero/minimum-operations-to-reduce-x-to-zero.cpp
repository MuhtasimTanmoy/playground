// class Solution {
//     int minOps = INT_MAX;
//     void traverse(vector<int>& nums, int left, int right, int remain, int ops) {
//         if (!remain) {
//             minOps = min(minOps, ops);
//             return;
//         }
//         if (left > right) return;

//         traverse(nums, left + 1, right, remain - nums[left], ops + 1 );
//         traverse(nums, left, right - 1, remain - nums[right], ops + 1 );
//     }

// public:
//     int minOperations(vector<int>& nums, int x) {
//         traverse(nums, 0, size(nums) - 1, x, 0 );
//         return minOps == INT_MAX ? -1 : minOps ;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>>dp;

//     int solve(vector<int>&nums,int s,int e,int x,int count=0){
//         if( x == 0 ) return count;
//         if( s > e ) 
//             return INT_MAX;
//         if(dp[s][e] != -1) return dp[s][e];
//         int leftSide = solve(nums, s+1, e, x - nums[s], count + 1 );
//         int rightSide = solve(nums, s, e-1, x - nums[e], count + 1 );
        
//         return dp[s][e] = min(leftSide,rightSide);
        
//     }
//     int minOperations(vector<int>& nums, int x) {
//         dp.resize(nums.size(),vector<int>(nums.size(),-1));
//         int res=solve(nums,0,nums.size()-1,x);
//         return res==INT_MAX?-1:res;
//     }
// };

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        map<int, int> suffixSumWithIndex;
        suffixSumWithIndex[0] = 0;
        int sum = 0;
        
        for(int i = size(nums) - 1; i >= 0; i--) {
            sum += nums[i];
            suffixSumWithIndex[sum] = size(nums) - i;
        }
        
        int minOps = suffixSumWithIndex.count(x) ? suffixSumWithIndex[x] : INT_MAX;
        sum = 0;
        for(int i = 0; i < size(nums); i++) {
            sum += nums[i];
            
            if (suffixSumWithIndex.count(x - sum)) {
                if (suffixSumWithIndex[x - sum] + i + 1 < size(nums)) {
                    minOps = min(minOps, suffixSumWithIndex[x - sum] + i + 1);
                }
            }
        }
        
        return minOps == INT_MAX ? -1 : minOps;
    }
};