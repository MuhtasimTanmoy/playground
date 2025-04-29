// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& N, int k) {
//          for (auto &n: N) n %= k;
//          for (auto l = 0, r = 0, sum = 0; r < N.size(); r++) {
//              sum += N[r];
//              while (sum > k) sum -= N[l++];
//              if (sum == k) return true;
//          }
//          return false;
//     }
// };

class Solution {
public:
    bool checkSubarraySum(vector<int>& N, int k) {
        unordered_map<int, int> dp;
        dp[0] = -1;
        for (auto r = 0, sum = 0; r < N.size(); r++) {
             sum += N[r],
             sum %= k;
             if (dp.count(sum)) {
                auto len = r - dp[sum];
                if (len > 1) return true;
             } else dp[sum] = r;
         }
         return false;
    }
};

// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         if (nums.size() < 2) return false;
//         unordered_map<int, int> mp;
//         mp[0] = -1;
        
//         int runningSum = 0;
//         for(int i = 0; i < nums.size(); i++) {
//             runningSum += nums[i];
//             runningSum = runningSum%k;
            
//             if(mp.find(runningSum)!=mp.end())
//             {
//                 //if it exists, then the current location minus the previous location must be greater than1
                
//                 if(i-mp[runningSum]>1)
//                     return true;
//             }
//             else
//             {
//                 //otherwise if the current runningSum doesn't exist in the hashmap, then store it as it maybe used later on
                
//                 mp[runningSum]=i;
//             }
                    
//         }
        
//         return false;
        
//     }
// };