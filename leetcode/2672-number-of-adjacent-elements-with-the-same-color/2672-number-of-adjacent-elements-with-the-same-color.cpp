class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& qs) {
        vector<int> li(n + 3), ans;
        int res = 0;
        for (auto q: qs) {
            auto i = q[0] + 1, v = q[1];
            if (li[i]) res -= (li[i-1] == li[i]) + (li[i] == li[i+1]);
            li[i] = v;
            res += (li[i-1] == li[i]) + (li[i] == li[i+1]);
            ans.push_back(res);
        }
        return ans;
    }
};