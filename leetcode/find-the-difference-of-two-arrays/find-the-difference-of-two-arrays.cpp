class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> num1Map(begin(nums1), end(nums1));
        unordered_set<int> num2Map(begin(nums2), end(nums2));
        vector<vector<int>> result(2, vector<int>());
        for(auto x: num1Map) if (!num2Map.count(x)) result[0].push_back(x);
        for(auto x: num2Map) if (!num1Map.count(x)) result[1].push_back(x);
        return result;
    }
};