class Solution {
public:
    #define mod 1000000007
    typedef long long ll;

    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<ll> prefix_sum(n + 1);
        for (int i = 0; i < n; i++) {
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
        }

        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if (st.empty()) left[i] = -1;
            else left[i] = st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if (st.empty()) right[i] = n;
            else right[i] = st.top();
            st.push(i);
        }

        ll res = 0;
        for (int i = 0; i < n; i++) {
            ll sub_sum = prefix_sum[right[i]] - prefix_sum[left[i]+1];
            ll min_val = nums[i];
            ll min_product = min_val * sub_sum;
            res = max(res, min_product);
        }
        return res % mod;
    }
};


