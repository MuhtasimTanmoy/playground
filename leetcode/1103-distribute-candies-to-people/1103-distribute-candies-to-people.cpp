class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int take = 1;
        vector<int> res(num_people, 0);
        while (candies > 0) {
            auto index = (take - 1) % num_people;
            res[index] += min(take, candies);
            candies -= take;
            take++;
        }
        return res;
    }
};