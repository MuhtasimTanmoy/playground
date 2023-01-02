class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> bag;
        for (auto type: candyType) bag.insert(type);
        return min(bag.size(), (candyType.size() >> 1));
    }
};