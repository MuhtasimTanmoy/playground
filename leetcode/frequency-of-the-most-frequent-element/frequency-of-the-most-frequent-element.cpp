
// This solution wont work because it considers all item to its left is taken, where in actual items can be left out

// class Solution {
// public:
//     int maxFrequency(vector<int>& nums, int k) {
        
//         sort(nums.begin(), nums.end());
        
//         vector<int> cSum(size(nums));
//         cSum[0] = nums[0];
//         for(int i = 1; i < size(nums); i++) cSum[i] = cSum[i-1] + nums[i];
        
//         int left = 4;
//         int right = size(nums) - 1;
        
//         auto toAttain = [&](int index) -> int {
//             int leftVals = cSum[index] - nums[index];
//             int indexToZero = index * nums[index];
//             return indexToZero - leftVals;
//         };
        
//         int result = 0;
//         while(left <= right) {
//             int mid = left + ( (right-left) >> 1 );
//             cout<<mid<<endl;
//             // cout<<nums[mid]<<endl;
//             auto toAttainNeeded = toAttain(mid);
//             cout<<toAttainNeeded<<endl;
//             // cout<<"-------"<<endl;
//             if (toAttainNeeded <= k) { result = mid; left = mid + 1; }
//             else right = mid - 1;
//         }
        
//         return result + 1;
//     }
// };

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        long long left = 0;
        long long right = 0;
        
        long long total = 0;
        long long result = 0;
        
        while(right < size(nums)) {
            
            total += nums[right];
            
            while ((right - left + 1) * nums[right] - total > k) {
                total -= nums[left];
                left++;
            }
            
            result = max(result, right - left + 1);
            right++;
        }
        
        return result;
    }
};