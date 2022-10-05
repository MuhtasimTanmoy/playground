class Solution {
public:
    int subtractProductAndSum(int n) {
        int multi = 1;
        int addi = 0;
        while(n) {
            int a = n % 10;
            addi += a;
            multi *= a;
            n = n / 10;
        }
        return multi-addi;
    }
};