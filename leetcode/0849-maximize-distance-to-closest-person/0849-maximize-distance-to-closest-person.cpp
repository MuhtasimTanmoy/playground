class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0, len = seats.size();
        for (int i = 0, l = -1; i < len; i++) 
            if (seats[i]) {
                auto dist = l == -1 ? 2 * i: i - l;
                res = max(res, dist / 2);
                l = i;
            } else if (i == len - 1) res = max(res, i - l);
        return res;
    }
};