class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto bill: bills) 
            if (bill == 5) five++;
            else if (bill == 10) {
                if (!five) return false;
                five--;
                ten++;
            } else {
                auto substract = 15;
                if (ten) { substract -= 10; ten--; }
                if (five - (substract / 5) < 0) return false;
                five -= (substract / 5);
            }
        return true;
    }
};