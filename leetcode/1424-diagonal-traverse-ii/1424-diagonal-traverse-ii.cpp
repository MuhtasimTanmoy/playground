class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<pair<int, int>> pos;
        for (auto i = 0; i < nums.size(); i++)
            for (auto j = 0; j < nums[i].size(); j++)
                pos.emplace_back(i, j);
        sort(pos.begin(), pos.end(), [](auto a, auto b) {
            auto [x, y] = a; 
            auto [m, n] = b;
            if ((x + y) == (m + n)) return x > m;
            return (x + y) < (m + n);
        });
        vector<int> res;
        for (auto [x, y]: pos) res.push_back(nums[x][y]);
        return res;    
    }
};