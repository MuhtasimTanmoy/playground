/*
110 / 112 test cases passed.

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int len = nums.size(), res = 0;
        for (int i = 0; i < len; i++) {
            bool is_positive = true;
            for (int j = i; j < len; j++) {
                if (!nums[j]) break;
                if (nums[j] < 0) is_positive = !is_positive;
                if (is_positive) res = max(res, j - i + 1);
            }
        }
        return res;
    }
};
*/

class Solution {
    const int NEG_FLAG = -2;
public:
    int getMaxLen(vector<int>& nums) {
        int res = 0;
        for (int i = 0, l = -1, 
             first_neg = NEG_FLAG, neg_count = 0; i < nums.size(); i++) {
            
            if (nums[i] == 0) l = i, first_neg = NEG_FLAG, neg_count = 0;
            else if (nums[i] < 0) neg_count++;
            
            if (neg_count == 1 && first_neg == NEG_FLAG) first_neg = i;
            
            if (neg_count & 1) res = max(res, i - first_neg);
            else res = max(res, i - l);
        }
        return res;
    }
};