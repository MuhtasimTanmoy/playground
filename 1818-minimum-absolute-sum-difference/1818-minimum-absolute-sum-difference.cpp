class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, 
                           vector<int>& nums2) {
        int mod = 1e9 + 7;
        long gain = 0, res = 0;
        set<int> s(nums1.begin(), nums1.end());
        for (int i = 0; i < nums1.size(); i++) {
            auto first = nums1[i], second = nums2[i];
            long diff = abs(first - second);
            res += diff;
            if (gain < diff) {
                auto near = s.lower_bound(second);
                if (near != s.end()) gain = max(gain, diff - abs(*near - second));
                if (near != s.begin()) gain = max(gain, diff - abs(*prev(near) - second));
            }
        }
        return (res - gain) % mod;
    }
};