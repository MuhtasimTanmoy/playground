class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, 
                                       vector<vector<int>>& queries) {
        vector<int> ids(nums.size()), res;
        iota(begin(ids), end(ids), 0);
        for(auto &q : queries) {
            int k = q[0], start = nums[0].size() - q[1];
            nth_element(begin(ids), begin(ids) + k - 1, end(ids), [&](int i, int j){
                int cmp = nums[i].compare(start, string::npos, nums[j], start, string::npos);
                return cmp == 0 ? i < j : cmp < 0;
            });
            res.push_back(ids[k - 1]);
        }
        return res;
    }
};