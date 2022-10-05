class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int steps = 0;
        while(target != 1) {
            if ( target & 1 ) {
                target--;
                steps++;
            } else if (maxDoubles) {
                maxDoubles--;
                target >>= 1;
                steps++;
            } else {
                steps += target - 1;
                target = 1;
            }
        }
        return steps;
    }
};