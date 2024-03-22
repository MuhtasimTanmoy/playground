class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int k = pattern.size(), res = 0;
        auto is_match_at = [&](int offset) {
            for (auto i = 0; i < k; i++) {
                auto idx = offset + i;
                auto one = nums[idx], two = nums[idx + 1];
                if (one == two)
                    if (pattern[i] != 0) return false;
                if (one < two)
                    if (pattern[i] != 1) return false;
                if (one > two)
                    if (pattern[i] != -1) return false;
            }
            return true;
        };
        for (auto i = 0; i < nums.size() - k; i++) 
            if (is_match_at(i)) 
                    res++;
        return res;
    }
};