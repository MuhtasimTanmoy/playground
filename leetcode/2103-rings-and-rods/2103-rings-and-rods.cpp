class Solution {
public:
    int countPoints(string rings, int res = 0) {
        vector<unordered_set<char>> rods(10);
        for (int i = 0; i < rings.size(); i += 2) {
            auto pos = rings[i + 1] - '0';
            auto val = rings[i];
            rods[pos].insert(val);
        }
        for (auto val: rods) if (val.size() == 3) res++;
        return res;
    }
};