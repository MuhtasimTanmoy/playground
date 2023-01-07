class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles) {
            auto renew = numBottles / numExchange;
            if (!renew) break;
            
            auto rest = numBottles % numExchange;
            ans += renew;
            numBottles = rest + renew;
        }
        return ans;
    }
};