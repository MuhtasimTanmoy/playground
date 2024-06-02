class Solution {
public:
    // vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {  
    //     vector<int> defaults;
    //     for (auto i = 1; i < nums.size(); i++)
    //         if ((nums[i] & 1) == (nums[i-1] & 1))
    //             defaults.push_back(i);
    //     vector<bool> res;
    //     for (auto q: queries) {
    //         auto from = q.front(), to = q.back();
    //         bool inserted = false;
    //         for (auto d: defaults)
    //             if (d > from && d <= to) {
    //                 res.push_back(false); inserted = true; break;
    //             }
    //         if (!inserted) res.push_back(true);
    //     }
    //     return res;
    // }
    
    // https://leetcode.com/problems/special-array-ii/discuss/5177194/Prefix-Sum
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ps{0};
        for (int i = 1; i < nums.size(); ++i)
            ps.push_back(ps.back() + (nums[i - 1] % 2 == nums[i] % 2));
        vector<bool> res;
        for (const auto &q : queries)
            res.push_back(ps[q[0]] == ps[q[1]]);
        return res;
    }
};