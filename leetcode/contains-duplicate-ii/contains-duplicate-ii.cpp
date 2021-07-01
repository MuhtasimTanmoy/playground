class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        vector<pair<int,int>> indexedNums;
        for(int i=0; i< nums.size() ; i++) {
            indexedNums.push_back(make_pair(nums[i], i));
        }
        
        sort(indexedNums.begin(), indexedNums.end());
        
        for(int i=0; i< nums.size() - 1; i++) {
            if (indexedNums[i].first == indexedNums[i + 1].first) {
                if (abs(indexedNums[i].second - indexedNums[i + 1].second) <= k) {
                    return true;
                }
            }
        }
        
        return false;
    }
};