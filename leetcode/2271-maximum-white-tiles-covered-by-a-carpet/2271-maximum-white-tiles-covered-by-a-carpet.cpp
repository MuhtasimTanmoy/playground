class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        auto got = 0, res = 0;
        for (int i = 0, j = 0; res < carpetLen && i < tiles.size();) {
            auto start = tiles[i][0], end = tiles[i][1];
            auto to = tiles[j][0] + carpetLen;
            if (to > end) {
                got += end - start + 1;
                res = max(res, got);
                i++;
            } else {
                auto partial = max(0, to - start);
                res = max(res, got + partial);
                got -= (tiles[j][1] - tiles[j][0] + 1);
                j++;
            }
        }
        return res;
    }
};