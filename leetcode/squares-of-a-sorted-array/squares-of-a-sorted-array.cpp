// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         for(auto &num: nums) num = num * num;
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = size(nums) - 1;
        
        int traverse = right;
        vector<int> result(size(nums));
        
        while(traverse >= 0) {
            int leftElem = abs(nums[left]);
            int rightElem = abs(nums[right]);
            
            if (leftElem > rightElem) {
                left++;
                result[traverse--] = leftElem * leftElem;
            } else {
                right--;
                result[traverse--] = rightElem * rightElem;
            }
        }
        
        return result;
    }
};