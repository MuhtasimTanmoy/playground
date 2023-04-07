class Solution {
public:
    int miceAndCheese(vector<int>& l, 
                      vector<int>& r, int k) {
        
        vector<int> idx(l.size(), 0);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](auto i, auto j) {
            return (l[i] - r[i]) > (l[j] - r[j]);
        });
                
        int sum = 0, len = l.size() - 1;
        for (int i = 0; i < k; i++) sum += l[idx[i]];
        for (int i = len; i >= k; i--) sum += r[idx[i]];
        return sum;
    }
};