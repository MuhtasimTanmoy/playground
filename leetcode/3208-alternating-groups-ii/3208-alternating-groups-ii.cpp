class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), res = 0;
        for (auto i = 1, l = 0; i < n + k; i++) 
            if (colors[i % n] == colors[ (i - 1 ) % n]) l = i - 1;
            else {
                l = max(l, i - k);
                if (i - l == k) res++;
            }
        return res;
    }
};