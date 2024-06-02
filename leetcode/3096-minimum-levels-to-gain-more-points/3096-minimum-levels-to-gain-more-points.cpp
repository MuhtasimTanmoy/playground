class Solution {
public:
    int minimumLevels(vector<int>& P) {
        int n = P.size();
        vector<int> reverse_win;
        for (auto i = n - 1, curr = 0; i >= 0; i--) 
            curr += P[i] ? 1: -1,
            reverse_win.push_back(curr);
        for (auto i = 0, now = 0; i < n - 1; i++) {
            now += P[i] ? 1: -1;
            if (now > reverse_win[n - i - 2]) return i + 1;
        }
        return -1;
    }
};