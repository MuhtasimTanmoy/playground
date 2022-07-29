class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int moves = 0;
        while(target > 0) target -= ++moves;
        return target % 2 == 0 ? moves: moves + 1 + (moves % 2);
    }
};