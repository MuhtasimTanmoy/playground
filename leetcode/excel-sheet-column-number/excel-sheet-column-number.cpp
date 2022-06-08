class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for(auto c: columnTitle) 
             res = res * 26 + (c-'A') + 1;
        return res;
    }
};