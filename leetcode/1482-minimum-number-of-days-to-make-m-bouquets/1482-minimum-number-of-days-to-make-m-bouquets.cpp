class Solution {
public:
    int minDays(vector<int>& bloom, int m, int k) {
        if ((long long) m * k > bloom.size()) return -1;
        
        auto can = [&](int upto) {
            int need = m, adjacent = 0;
            for (auto day: bloom) {
                adjacent = day <= upto ? adjacent + 1: 0;
                if (adjacent == k) adjacent = 0, need--;
            }
            return need <= 0;     
        };
        
        int l = 1, r = 1e9;
        while (l < r) {
            auto m = l + (r - l) / 2;
            if (can(m)) r = m; else l = m + 1;
        }
        return r;
    }
};