class Solution {
public:
    int kItemsWithMaximumSum(int n1, int n0, int nneg, int k) {
        auto left = k - n1 - n0;
        return left <= 0 ? min(n1, k): n1 - min(nneg, left);
    }
};