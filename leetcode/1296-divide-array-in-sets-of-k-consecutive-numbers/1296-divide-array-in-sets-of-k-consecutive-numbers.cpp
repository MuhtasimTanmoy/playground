class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        auto maxElem = *max_element(nums.begin(), nums.end());
        int total = nums.size();
        if (total % k != 0) return false;
        
        vector<int> tracker(maxElem + 1, 0);
        for (auto num: nums) tracker[num]++;
        
        for (int i = 0; i < tracker.size() - k + 1; i++) {
            auto toDeduct = tracker[i];
            if (!toDeduct) continue;
            
            for (int j = i; j < i + k; j++) {
                if (tracker[j] < toDeduct) return false;
                tracker[j] -=  toDeduct;
            }
            total -= toDeduct * k;
        }
        return !total;        
    }
};