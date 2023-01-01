class Solution {
public:
    int findComplement(int num) {
        auto track = num, bit = 1;
        while (track) {
            num = num ^ bit;
            bit = bit << 1;
            track = track >> 1;
        }
        return num;
    }
};