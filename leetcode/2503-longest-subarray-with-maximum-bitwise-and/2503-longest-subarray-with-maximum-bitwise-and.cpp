class Solution {
public:
    int longestSubarray(vector<int>& N) {
        int len = 1;
        auto max_num = *max_element(N.begin(), N.end());
        for (auto i = 1, calc_len = 1; i < N.size(); i++) {
            if (N[i] == N[i-1] && N[i] == max_num) calc_len++; else calc_len = 1;
            len = max(len, calc_len);
        }
        return len;
    }
};