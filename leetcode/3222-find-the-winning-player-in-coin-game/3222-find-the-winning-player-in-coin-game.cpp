class Solution {
public:
    string losingPlayer(int x, int y) {
        y = y / 4;
        bool alice_turn = true;
        while (x && y) x--, y --, alice_turn = !alice_turn;
        return alice_turn ? "Bob" : "Alice";
    }
};