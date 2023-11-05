class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        vector<int> res(n, 1);
        
        for (int i = 1; i < n; i++) 
            if (r[i - 1] < r[i]) res[i] = res[i - 1] + 1;
        
        for (int i = n - 2; i >= 0; i--) 
            if (r[i] > r[i + 1]) res[i] = max(res[i], res[i + 1] + 1);
        
        auto sum = accumulate(res.begin(), res.end(), 0);
        return sum;
    }
};