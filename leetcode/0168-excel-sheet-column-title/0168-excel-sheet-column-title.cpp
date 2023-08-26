class Solution {
    int pivot = 26;
public:
    string convertToTitle(int col, string res = "") {
        while (col) 
            res +=  'A' + (col - 1) % 26,
            col = (col - 1) / 26;
        reverse(res.begin(), res.end());
        return res;
    }
};