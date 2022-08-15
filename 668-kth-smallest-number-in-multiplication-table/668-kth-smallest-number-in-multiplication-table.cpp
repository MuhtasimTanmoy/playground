class Solution {
public:
    bool check(int x,int m,int n,int k) {
        auto cnt = 0;
        for (auto i = 1; i <= m; i++) {
            auto j = x / i;
            cnt += min(j, n);
        }
        return cnt >= k;
    }
    
    int findKthNumber(int m, int n, int k) {
        auto l = 0, r = m * n;
        while ( r - l > 1 ) {
            auto mid = (l + r) >> 1;
            if (check(mid, m, n, k)) r = mid;
            else l = mid;
        }
        return r;
    }
};