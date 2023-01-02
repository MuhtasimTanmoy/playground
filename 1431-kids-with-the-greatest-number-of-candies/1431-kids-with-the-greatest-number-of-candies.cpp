class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int most = INT_MIN;
        for (auto candy: candies) most = max(most, candy);
        vector<bool> res(candies.size(), false);
        for (int i = 0; i < candies.size(); i++) 
            if (candies[i] + extraCandies >= most) 
                res[i] = true;
        return res;
    }
};