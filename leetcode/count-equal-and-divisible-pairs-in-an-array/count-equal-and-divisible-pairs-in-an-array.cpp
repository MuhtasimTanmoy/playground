class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> bag;
        int count = 0;
        for(int i =0; i < size(nums); i++) {
            if (bag.count(nums[i])) {
                for(auto prevIndex: bag[nums[i]]) {
                    if ( ( i * prevIndex) % k == 0 ) count++;
                }
            }
            bag[nums[i]].push_back(i);
        }
        return count;
    }
};