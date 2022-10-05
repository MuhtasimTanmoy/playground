// class Solution {
// public:
//     int hammingDistance(int x, int y) {
//         int i = 31, res = 0;
//         while (i--) {
//             auto xPos = (x >> i) & 1;
//             auto yPos = (y >> i) & 1;
//             if ( xPos != yPos ) res++;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xord = x ^ y;
        return __builtin_popcount(xord);
    }
};