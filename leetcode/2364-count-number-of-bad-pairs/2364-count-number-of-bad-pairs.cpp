class Solution {
public:
    // long long countBadPairs(vector<int>& nums, int res = 0) {
    //     for (int i = 0; i < nums.size() - 1; i++)
    //         for (int j = i + 1; j < nums.size(); j++)
    //             if (j - i != nums[j] - nums[i])
    //                 res++;
    //     return res;
    // }
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