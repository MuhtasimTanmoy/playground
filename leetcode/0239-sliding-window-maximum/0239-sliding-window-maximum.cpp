class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> mset;
        for (auto l = 0, r = 0; r < nums.size(); r++) {
            mset.insert(nums[r]);
            if (mset.size() > k) mset.erase(mset.find(nums[l++]));
            if (mset.size() == k) res.push_back(*mset.rbegin());
        }
        return res;
    }
};