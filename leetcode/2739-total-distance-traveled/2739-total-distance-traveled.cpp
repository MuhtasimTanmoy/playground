class Solution {
public:
    int distanceTraveled(int main, int add) {
        int res = 0;
        while (main >= 5) {
            main -= 5;
            if (add) 
                add--,
                main += 1;
            res += 5;
        }
        res += main;
        return res * 10;
    }
};