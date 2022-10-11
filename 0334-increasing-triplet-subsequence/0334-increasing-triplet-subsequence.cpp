// Gets TLE

/*
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        for (int i = 1; i < nums.size() - 1; i++) {
            auto mid = nums[i];
            int leftItr = i - 1;
            bool left = false;
            while (leftItr >= 0) 
                if (nums[leftItr--] < mid) {
                    left = true;
                    break;
                }
            int rightItr = i + 1;
            bool right = false;
            while (rightItr < nums.size()) 
                if (nums[rightItr++] > mid) {
                    right = true;
                    break;
                }
            if (left && right) return true;
        }
        return false;
    }
};
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for (auto num: nums) {
            if (first >= num) first = num;
            else if (second >= num) second = num;
            else return true;
        }
        return false;
    }
};