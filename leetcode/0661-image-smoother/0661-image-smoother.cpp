class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        auto shouldGo = [&](int p, int q) {
            if (p < 0 || p >= img.size() || q < 0 || q >= img[p].size()) return false;
            return true;
        };
        for (auto i = 0; i < img.size(); i++) 
            for (auto j = 0; j < img[i].size(); j++) {
                int sum = 0, count = 0;
                for (int x = -1; x <= 1; x++) 
                    for (int y = -1; y <= 1; y++) 
                        if (shouldGo(i + x, j + y)) 
                            sum += img[i + x][j + y] & 0xFF, count++;
            img[i][j] |= (sum / count) << 8;
        }
        for (auto i = 0; i < img.size(); i++) 
            for (auto j = 0; j < img[i].size(); j++) 
                img[i][j] = img[i][j] >> 8;
        return img;
    }
};