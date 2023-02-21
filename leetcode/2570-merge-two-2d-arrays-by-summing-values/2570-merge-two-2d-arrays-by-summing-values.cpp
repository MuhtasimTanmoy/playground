class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, 
                                    vector<vector<int>>& nums2) {
        vector<int> calc(1001, 0);
        for (auto num: nums1) calc[num[0]] += num[1];
        for (auto num: nums2) calc[num[0]] += num[1];
        vector<vector<int>> res;
        for (auto i = 0; i < 1001; i++) 
            if (calc[i]) 
                res.push_back({i, calc[i]});
        return res;
    }
};