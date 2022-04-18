class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> bag;
        unordered_set<int> resultBag;
        for(auto num: nums1) bag.insert(num);
        for(auto num: nums2) if ( bag.count(num) ) resultBag.insert(num);
        return vector<int>(begin(resultBag), end(resultBag));
    }
};