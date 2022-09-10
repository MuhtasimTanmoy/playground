// As a result, we then can reformulate the problem as "given two integer numbers, we are asked to find the common prefix of their binary strings."

// class Solution {
// public:
//     int rangeBitwiseAnd(int left, int right) {
//         int res = left;
//         for (int i = left + 1; i <= right; i++) {
//             res &= i;
//             if (!res) break;
//         }
//         return (int)res;
//     }
// };

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int m = left, n = right, shift = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            shift++;
        }
        return m << shift;
    }
};