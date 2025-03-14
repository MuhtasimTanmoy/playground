class Solution {
public:
    long long countBadPairs(vector<int>& nums, long long res = 0) {
        unordered_map<int, int> cache;
        for (int i = 0; i < nums.size(); i++) {
            auto key = nums[i] - i;
            res += i - cache[nums[i] - i];
            ++cache[key]; 
        }
        return res;
    }
};



// j - i != nums[j] - nums[i]
// j - nums[j] != i - nums[i]