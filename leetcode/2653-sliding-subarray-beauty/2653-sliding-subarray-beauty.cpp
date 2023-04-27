class Solution {
    const int OFFSET = 50;
public:
    vector<int> getSubarrayBeauty(vector<int>& n, int k, int x) {
        vector<int> cnt(101, 0);
        
        // gets the xth element
        auto get_xth_elem = [&]() {
            for (int i = 0, xth = x; i < 101; xth -= cnt[i], i++) 
                if (xth <= cnt[i]) 
                    return min(i - OFFSET, 0);
            throw "error";
        };
        
        vector<int> res;
        for (int l = -k, r = 0; r < n.size(); l++, r++) {
            cnt[n[r] + OFFSET]++;
            if (l >= 0) cnt[n[l] + OFFSET]--;
            if (l + 1 >= 0) res.push_back(get_xth_elem());
        }
        return res;
    }
};