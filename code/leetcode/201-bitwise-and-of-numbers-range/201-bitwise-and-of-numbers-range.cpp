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

// class Solution {
// public:
//     int rangeBitwiseAnd(int left, int right) {
//         int m = left, n = right, shift = 0;
//         while (m != n) {
//             m >>= 1;
//             n >>= 1;
//             shift++;
//         }
//         return m << shift;
//     }
// };


// The secret sauce of the Brian Kernighan's algorithm can be summarized as follows:

// When we do AND bit operation between number and number-1, the rightmost bit of one in the original number would be turned off (from one to zero).

// The idea is that for a given range [m, n][m,n] (i.e. m < nm<n), we could iteratively apply the trick on the number nn to turn off its rightmost bit of one until it becomes less or equal than the beginning of the range (mm), which we denote as n'n 
// ′
//  . Finally, we do AND operation between n'n 
// ′
//   and mm to obtain the final result.

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int m = left, n = right, shift = 0;
        while (m < n)  n = n & (n - 1);
        return m & n;
    }
};