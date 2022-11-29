class Solution {
public:
    int countAsterisks(string s) {
        int numberOfSpecialChar = 0;
        bool shouldCount = true;
        for (auto c: s) {
            
            if (c == '|') {
                shouldCount = !shouldCount;
                continue;
            }
            
            if (shouldCount && c =='*') numberOfSpecialChar++;
        }
        return numberOfSpecialChar;
    }
};