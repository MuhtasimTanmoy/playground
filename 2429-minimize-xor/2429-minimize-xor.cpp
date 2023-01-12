class Solution {
    // 0011001
    // 1001000
public:
    int minimizeXor(int num1, int num2) {
        auto x = num1;
        auto toAddInX = __builtin_popcount(num2) - __builtin_popcount(x);
        cout<<toAddInX<<endl;
        
        if (toAddInX > 0) {
            int traverse = 0;
            while (toAddInX) {
                if (x & (1 << traverse)) {} else {
                    x |= 1 << traverse;
                    toAddInX--;
                }
                traverse++;
            }
        } 
        
        if (toAddInX < 0) {
            int traverse = 0;
            while (toAddInX != 0) {
                if (x & (1 << traverse)) {
                    x ^= 1 << traverse;
                    toAddInX++;
                }
                traverse++;
            }
        } 
        
        return x;
    }
};