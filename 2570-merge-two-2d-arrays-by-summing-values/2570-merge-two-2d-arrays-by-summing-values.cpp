class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, 
                                    vector<vector<int>>& nums2) {
        map<int, int> calc;
        for (auto num: nums1) calc[num[0]] += num[1];
        for (auto num: nums2) calc[num[0]] += num[1];
        vector<vector<int>> res;
        for (auto [id, val]: calc) res.push_back({id, val});
        return res;
    }
};