class Solution {
public:
    
    // 387 / 533 test cases passed.
    /*
    int minSizeSubarray(vector<int>& nums, int target, int res = 0) {
        int n = nums.size();
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        cout<<sum<<endl;
        
        if (target > sum) {
            auto count = target / sum;
            target -= count * sum;
            res += count * n;
        }
        cout<<target<<endl;
        target = sum - target;

        int len = INT_MIN;
        for (int l = 0, r = 0, sum = 0; r < n; r++) {
            sum += nums[r];
            while (sum > target) sum -= nums[l++];
            if (sum == target) len = max(len, r - l + 1);
        }
        return len == INT_MIN ? -1: res + n - len;
    }
    */
    
    int minSizeSubarray(vector<int>& nums, int target) {
        long long all = accumulate(begin(nums), end(nums), 0LL);
        int n = nums.size(), dist = INT_MAX, t = target - target / all * all;
        for (int i = 0,  j = 0, sum = 0; i < 2 * n; ++i) {
            sum += nums[i % n];
            while (sum > t) sum -= nums[j++ % n];
            if (sum == t) dist = min(dist, i - j + 1);
        }
        return dist == INT_MAX ? -1 : target / all * n + dist;
    }
};