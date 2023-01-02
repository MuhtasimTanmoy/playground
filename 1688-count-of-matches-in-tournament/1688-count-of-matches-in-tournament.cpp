class Solution {
public:
    int numberOfMatches(int n) {
        int played = 0;
        while (n != 1) 
            if (n & 1) {
                auto match = (n - 1) >> 1;
                played += match;
                n = match + 1;
            } else {
                auto match = n >> 1;
                played += match;
                n = match;
            }
        return played;
    }
};