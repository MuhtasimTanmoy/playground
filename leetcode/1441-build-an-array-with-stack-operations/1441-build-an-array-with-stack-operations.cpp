class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n, vector<string> res = {}) {
        auto len = target.size();
        for (int i = 1, j = 0; i <= n && j < len; i++) {
            res.push_back("Push");
            if (target[j] == i) j++; else res.push_back("Pop");
        }
        return res;
    }
};