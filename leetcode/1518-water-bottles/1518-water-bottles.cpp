class Solution {
public:
    int numWaterBottles(int have, int exchange_rate) {
        if (have < exchange_rate) return have;
        auto left = have % exchange_rate, consume = have - left;
        return consume + numWaterBottles(consume / exchange_rate +  left, exchange_rate);
    }
};