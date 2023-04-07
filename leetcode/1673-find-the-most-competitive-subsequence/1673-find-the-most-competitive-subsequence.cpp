class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res; auto addition = nums.size() - k;
        for (auto num: nums) {
            while (res.size() && addition && num < res.back()) {
                addition--;
                res.pop_back();
            }
            res.push_back(num);
        }
        return {res.begin(), res.begin() + k};
    }
};