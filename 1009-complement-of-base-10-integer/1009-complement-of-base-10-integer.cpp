class Solution {
public:
    int bitwiseComplement(int n) {
        auto cache = n; int bit = 1;
        do  {
            n = n ^ bit;
            bit = bit << 1;
            cache = cache >> 1;
        } while (cache);
        return n;
    }
};