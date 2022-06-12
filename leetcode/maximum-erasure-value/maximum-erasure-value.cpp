class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_multiset<int> tracker;
        int res = 0;
        int left = -1, right = 0;
        int sum = 0;
        
        while(right < nums.size()) {
            auto target = nums[right++];          
            while(tracker.count(target)) {
                tracker.erase(nums[++left]);
                sum -= nums[left];
            }
            
            tracker.insert(target);
            sum += target;
            res = max(res, sum);
        }
        return res;
    }
};