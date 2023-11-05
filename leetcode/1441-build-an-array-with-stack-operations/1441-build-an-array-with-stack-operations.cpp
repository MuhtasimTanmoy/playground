class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        for (auto i = 1, j = 0; i <= n; i++) {
            if (j >= target.size()) break;
            res.push_back("Push");
            if (target[j] != i) res.push_back("Pop"); else j++;
        }
        return res;
    }
};