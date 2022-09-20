class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int> jewelMap(128, 0);
        for (auto jewel: jewels) jewelMap[jewel] = 1;
        int res = 0;
        for (auto stone: stones) if (jewelMap[stone]) res++;
        return res;
    }
};