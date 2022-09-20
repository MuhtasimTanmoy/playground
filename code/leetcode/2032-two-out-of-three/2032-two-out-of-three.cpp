class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> tracker(101, 0);
        unordered_set<int> bag;
        for (auto i: nums1) tracker[i]++;
        for (auto i: nums2) if (tracker[i]) bag.insert(i);
        for (auto i: nums2) tracker[i]++;
        for (auto i: nums3) if (tracker[i]) bag.insert(i);
        return vector<int>(bag.begin(), bag.end());
    }
};