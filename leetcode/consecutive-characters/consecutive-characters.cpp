class Solution {
public:
    int maxPower(string s) {
        int consCharCount = 1;
        int maxConsCharCount = 1;
        for(int i = 1; i < size(s); i++) {
            if (s[i] == s[i-1]) consCharCount++;
            else consCharCount = 1;
            maxConsCharCount = max(maxConsCharCount, consCharCount);
        }
        return maxConsCharCount;
    }
};