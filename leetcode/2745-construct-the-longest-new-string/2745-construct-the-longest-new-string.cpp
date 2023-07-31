class Solution {
public:
    int longestString(int x, int y, int z) {
        return (min(x, y + 1) + min(x + 1, y) + z) * 2;
    }
};