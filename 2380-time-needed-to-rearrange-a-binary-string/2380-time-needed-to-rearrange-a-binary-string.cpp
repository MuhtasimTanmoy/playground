class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int zeros = 0, seconds = 0;
        for (int i = 0; i < s.size(); ++i) {
            zeros += s[i] == '0';
            if (s[i] == '1' && zeros) seconds = max(seconds + 1, zeros);
        }
        return seconds;
    }
};