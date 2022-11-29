class Solution {
public:
//     int minOperations(string s) {
//         int zeroDiff = 0, oneDiff = 0;
//         int zeroToken = '0', oneToken = '1';
//         for (auto c: s) {
//             if (c != zeroToken) zeroDiff++;
//             if (c != oneToken) oneDiff++;
//             swap(zeroToken, oneToken);
//         }
//         return min(zeroDiff, oneDiff);
//     }
    
    int minOperations(string s) {
        int res = 0, sz = s.length();
        for (int i = 0; i < sz; ++i)
            res += s[i] - '0' != i % 2;
        return min(res, sz - res);
    } 
};

