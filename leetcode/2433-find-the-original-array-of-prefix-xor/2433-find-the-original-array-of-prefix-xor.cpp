class Solution {
public:
    vector<int> findArray(vector<int>& pre) {
        for (auto i = pre.size() - 1; i > 0; i--)
            pre[i] ^= pre[i - 1];
        return pre;
    }
};