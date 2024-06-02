class Solution {
public:
    int countDays(int days, vector<vector<int>>& meets) {
        sort(meets.begin(), meets.end());
        int res = meets.front().front() - 1, max_so_far = meets.front().back();
        for (auto i = 1; i < meets.size(); i++) {
            auto has = meets[i].front() - max_so_far - 1;
            res += max(has, 0);
            max_so_far = max(max_so_far, meets[i].back());
        }
        res += days - max_so_far;
        return res;
    }
};