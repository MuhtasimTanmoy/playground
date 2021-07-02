class Solution {
    
    // Traverse the input array and replace all zeroes and negative number by INT_MAX
    // Traverse the input array again, and during this traversal we will find the correct position of each element by making value at that index negative.
    // During final traversal, return the (index+1) where "index" is the first index at which element found is positive.
    
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
