class Solution {
public:
    int passThePillow(int n, int time) {
        int l = time / (n - 1);
        time = time % (n - 1);
        return (l & 1) ? n - time: time + 1;
    }
};