class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        auto next_least = INT_MAX, least = INT_MAX;
        for (auto price: prices) 
            if (price < least) next_least = least, least = price;
            else if (next_least > price) next_least = price;
        auto total = next_least + least;
        return total <= money ? money - total : money;
    }
};