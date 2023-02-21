class Solution {
public:
    // int minOperations(int n) {
    //     int cont = 0, res = 0, int prev = -1;
    //     for (auto i = 0; i < 31; i++)
    //         if (n & (1 << i)) {
    //             if (cont == 0) res++;
    //             if (cont == 1) res++;
    //             cont++;
    //         } else cont = 0;
    //     return res;
    // }
    int minOperations(int n) {
        int res = 0;
        while (n > 0) 
            if ((n & 3) == 3) n++, res++;
            else {
                res += n & 1;
                n >>= 1;
            }
        return res;
    }
};