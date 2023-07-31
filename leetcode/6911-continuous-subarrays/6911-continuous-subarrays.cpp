class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        map<int, int> t;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            t[nums[r]]++;            
            while ( t.size() && (t.rbegin()->first - t.begin()->first) > 2 ) {
                if (--t[nums[l]] == 0) t.erase(nums[l]);
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }
};