class Solution {
public:
    int totalFruit(vector<int>& fruits, int res = 0) {
        unordered_map<int, int> kind;
        for (int i = 0, j = 0; i < fruits.size(); i++) {
            auto k = fruits[i];
            kind[k]++;
            while (kind.size() > 2) {
                auto toErase = fruits[j++];
                if (--kind[toErase] == 0) kind.erase(toErase);
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};