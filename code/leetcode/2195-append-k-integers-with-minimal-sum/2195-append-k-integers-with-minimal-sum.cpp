class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long missing = 1, res = 0;
        for (auto num: nums) {
            while ( missing < num ) {
                res += missing++;
                k--;
                if (!k) return res;
            }
            missing = num + 1;
        }
        while (k--) res += missing++;
        return res ;
    }
};