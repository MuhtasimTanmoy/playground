class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       
        for( int i = 0; i < nums.size(); i++ ) {
            if (nums[i] < 1) { nums[i] = INT_MAX; }
        }
        
        
        for( int i = 0; i < nums.size(); i++ ) {
            if ( abs(nums[i]) <= nums.size()) {
                nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
            }
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};




// Simple map based but have nlogn complexity
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         map<int,int>m;
//         for(int i=0;i<nums.size();i++)
//         {
//             m[nums[i]]++;
//         }
//         for(int i=1;i<=nums.size()+1;i++){
//             if(m[i]==0)
//                 return i;
//         }
//         return 1;
//     }
// };