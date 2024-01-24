class Solution {
public:
    int totalStrength(vector<int>& A) {
        A.push_back(0);
        int res = 0, ac = 0, mod = 1e9 + 7, n = A.size();
        vector<int> st = {}, acc(n + 2);
        for (int r = 0; r < n; ++r) {
            int a = A[r];
            ac = (ac + a) % mod;
            acc[r + 1] = (ac + acc[r]) % mod;
            while (!st.empty() && A[st.back()] > a) {
                int i = st.back(); st.pop_back();
                int l = st.empty() ? -1 : st.back();
                long lacc = l < 0 ? acc[i] : acc[i] - acc[l], racc = acc[r] - acc[i];
                int ln = i - l, rn = r - i;
                res = (res + (racc * ln - lacc * rn) % mod * A[i] % mod) % mod;
            }
            st.push_back(r);
        }
        return (res + mod) % mod;
    }
};