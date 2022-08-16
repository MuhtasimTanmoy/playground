class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0, itr = 31;
        while (itr--) {
            bool isDiff = (start >> itr) & 1 ^ (goal >> itr) & 1;
            if (isDiff) count++;
        }
        return count;
    }
};