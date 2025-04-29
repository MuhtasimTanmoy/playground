class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        
        unordered_set<int> pre {0};
        auto target = sum >> 1;
        for (auto num: nums) {
            unordered_set<int> c = pre;
            for (auto key: pre) c.insert(key + num);
            swap(pre, c);
        }
        return pre.count(target);
    }
};