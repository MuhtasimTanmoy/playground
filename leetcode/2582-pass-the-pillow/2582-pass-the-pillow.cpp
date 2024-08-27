class Solution {
public:
    int passThePillow(int n, int time) {
        auto times = time / (n - 1);
        time = time % (n - 1);
        return times & 1 ? n - time : time + 1;
    }
};