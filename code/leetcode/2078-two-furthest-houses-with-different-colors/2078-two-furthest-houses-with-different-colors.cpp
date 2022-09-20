class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int firstColor = colors[0], lastColor = colors[colors.size() - 1];
        if (firstColor != lastColor) return colors.size() - 1;
        int res = 0;
        for (int i = 1; i < colors.size() - 1; i++) {
            if (colors[i] != firstColor) res = max(res, i);
            if (colors[i] != lastColor) res = max(res, (int)colors.size() - i - 1);
        }
        return res;
    }
};