class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;

        int count = 10, multi = 9;
        for (int i = 1; i < n; i++) {
            multi *= 10 - i;
            count += multi;
        }

        return count;
    }
};