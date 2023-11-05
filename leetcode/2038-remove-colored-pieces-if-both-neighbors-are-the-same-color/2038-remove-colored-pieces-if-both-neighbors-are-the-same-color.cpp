class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size(), alice_win = 0;
        for (int i = 1; i < n - 1; i++) 
            if (colors[i - 1] == colors[i] && colors[i + 1] == colors[i])
                alice_win += colors[i] == 'A' ? 1: -1;
        return alice_win > 0;
    }
};