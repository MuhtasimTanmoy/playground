class Solution {
public:
    // int minPatches(vector<int>& nums, int n) {
    //     unordered_set<int> has(nums.begin(), nums.end());
    //     auto get_min_div = [](auto num) {
    //         for (auto i = 2; i <= sqrt(num); i++)
    //             if (num % i == 0)
    //                 return i;
    //         return num;
    //     };
    //     int res = 0;
    //     for (auto i = 1; i <= n; i++) {
    //         auto min_div = get_min_div(i);
    //         if (has.count(min_div)) continue;
    //         has.insert(min_div), res++;
    //     }
    //     return res;
    // }
    //https://leetcode.com/problems/patching-array/discuss/78488/Solution-%2B-explanation
    int minPatches(vector<int>& nums, int n) {
        long miss = 1, added = 0, i = 0;
        while (miss <= n) 
            if (i < nums.size() && nums[i] <= miss) 
                miss += nums[i++];
            else 
                miss += miss,
                added++;
        return added;
    }
    };