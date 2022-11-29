class Solution {
public:
    int pivotInteger(int n) {
        auto allsum = ( n * (n + 1) ) >> 1;
        int sum = 0, index = 1;
        while (sum <= allsum) {
            sum += index;
            if (2 * sum == (allsum + index)) return index;
            index++;
        }
        return -1;
    }
};