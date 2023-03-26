class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& s) {
        sort(s.begin(), s.end());
        
        auto first = *s.begin() - bottom;
        int interval = 0;
        for (int i = 1; i < s.size(); i++) interval = max(interval, s[i] - s[i-1] - 1);
        auto last = top - *s.rbegin();
        
        return max({first, last, interval});
    }
};