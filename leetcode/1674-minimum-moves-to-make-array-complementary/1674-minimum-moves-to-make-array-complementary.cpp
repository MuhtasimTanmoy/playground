class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int N = nums.size();
        vector<int> memo(limit * 2 + 2, 0);
        for (int i = 0; i < N / 2; ++i) {
            int l = nums[i], r = nums[N - 1 - i];
            --memo[min(l, r) + 1];
            --memo[l + r];
            ++memo[l + r + 1];
            ++memo[max(l, r) + limit + 1];
        }
        int ans = N, curr = N;
        for (int i = 2; i <= limit * 2; ++i) {
            curr += memo[i];
            ans = min(ans, curr);
        }
        return ans;
    }
};