class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> bag(101, 0);
        int pairCount = 0;
        int leftOver = 0;
        for (auto num: nums) bag[num]++;
        for (auto item: bag) {
            if (!item) continue;
            pairCount += (item / 2);
            leftOver += (item % 2);
        }
        return {pairCount, leftOver};
    }
};