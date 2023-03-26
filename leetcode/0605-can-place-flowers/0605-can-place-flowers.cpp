class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        auto sz = f.size();
        for (int i = 0; i < sz && n; i++) {
            auto can_be_planted = f[i] == 0;
            if (i) can_be_planted = can_be_planted && f[i-1] == 0;
            if (i < sz - 1) can_be_planted = can_be_planted && f[i+1] == 0;
            if (can_be_planted) n--, f[i] = 1;
        }
        return n == 0;
    }
};