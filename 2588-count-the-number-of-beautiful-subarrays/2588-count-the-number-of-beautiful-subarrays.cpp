/*
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums, long long res = 0) {
        for (int i = 0; i < nums.size(); i++) 
            for (int j = i, calc = 0; j < nums.size(); j++) {
                calc ^= nums[j];
                if (calc == 0) res++;
            }
        return res;
    }
};
*/

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums, long long res = 0) {
        unordered_map<int, int> cache; cache[0] = 1;
        int calc = 0;
        for (auto num: nums) {
            calc ^= num;
            res += cache[calc]++;
        }
        return res;
    }
};