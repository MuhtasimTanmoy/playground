class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> banned_set(banned.begin(), banned.end());
        int sum = 0, res = 0;
        for (int i = 1; i <= n; i++) {
            if (banned_set.count(i)) continue;
            sum += i;
            if (sum <= maxSum) res++; else break;
        }
        return res;
    }
};