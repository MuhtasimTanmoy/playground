class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxNum = 0, secondMax = 0;
        for (auto num: nums) {
            if (num > maxNum) {
                if (maxNum > secondMax) secondMax = maxNum;
                maxNum = num;
            } else if (num > secondMax) secondMax = num;
        }
        return (secondMax - 1) * (maxNum - 1);
    }
};