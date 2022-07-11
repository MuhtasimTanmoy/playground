class Solution {
public:
    int minimumMoves(string s) {
        int noCheck = 0;
        int res = 0;
        for(int i = 0 ; i < size(s); i++) {
            if (noCheck) noCheck--;
            else if (s[i] == 'X') {
                noCheck = 2;
                res++;
            }
        }
        return res;
    }
};