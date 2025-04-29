class Solution {
public:
    constexpr int static n = 100000;
    int bt[n + 1] = {};

    int prefix_sum(int i) {
        int sum = 0;
        for (i = i + 1; i > 0; i -= i & (-i)) sum += bt[i];
        return sum;
    }

    void add(int i, int val) {
        for (i = i + 1; i <= n; i += i & (-i)) bt[i] += val;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long res = 0, sz = nums1.size();
        vector<int> ids(sz);
        for (int i = 0; i < sz; ++i)
            ids[nums2[i]] = i;

        for (int i = 0; i < sz - 1; ++i) {
            int mid = ids[nums1[i]], 
                sm = prefix_sum(mid), 
                gr = sz - 1 - mid - (i - sm);

            res += (long long) sm * gr;
            add(mid, 1);
        }
        return res;
    }
};