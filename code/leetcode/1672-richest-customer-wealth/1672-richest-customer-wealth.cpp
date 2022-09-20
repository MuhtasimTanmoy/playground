class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (auto riches: accounts) {
            auto rich = accumulate(riches.begin(), riches.end(), 0);
            if (rich > ans) ans = rich;
        }
        return ans;
    }
};