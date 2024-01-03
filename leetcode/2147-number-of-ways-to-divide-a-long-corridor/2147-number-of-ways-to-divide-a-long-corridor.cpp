class Solution {
public:
    int numberOfWays(string corridor) {
        int x = 1; // 0 seat
        int y = 0; // 1 seat
        int z = 0; // 2 seats
        for (char& ch: corridor) {
            x = (x + z) % int(1e9 + 7);
            if (ch == 'S') z = y, y = x, x = 0;
        }
        return z;
    }
};