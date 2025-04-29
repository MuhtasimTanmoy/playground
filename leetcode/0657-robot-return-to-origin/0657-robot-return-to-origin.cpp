class Solution {
public:
    bool judgeCircle(string moves) {
        auto x = 0, y = 0;
        for (auto move: moves) 
            y += move == 'U',
            y -= move == 'D',
            x += move == 'R',
            x -= move == 'L';
        return !x && !y;
    }
};