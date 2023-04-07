class Solution {
    const int MOD = 1e9 + 7;
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        while (k--) {
            auto top = pq.top();
            pq.pop(), top++;
            pq.push(top);
        }
        long long res = 1;
        while (pq.size()) {
            auto i = pq.top(); pq.pop();
            res = ((i % MOD) * (res % MOD)) % MOD;
        }
        return res;
    }
};