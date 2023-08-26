class Solution {
public:
    int accountBalanceAfterPurchase(int amount) {
        auto add = (amount % 10) >= 5 ? (10 - amount % 10): -1 * (amount % 10);
        return 100 - (amount + add);
    }
};