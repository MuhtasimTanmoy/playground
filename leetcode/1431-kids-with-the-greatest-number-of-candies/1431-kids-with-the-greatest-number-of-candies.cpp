class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto max_candies = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        for (auto candy: candies)
            res.push_back( (candy + extraCandies) >= max_candies);
        return res;
    }
};