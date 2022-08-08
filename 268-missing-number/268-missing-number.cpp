class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum -=  nums[i];
            sum += i + 1;
        }
        return sum;
    }
};

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int sum = nums.size();
//         for (int i = 0; i < nums.size(); i++)
//             sum ^= (i ^ nums[i]);
//         return sum;
//     }
// };