class Solution {
public:
    int minimumChairs(string s) {
        int res = 0, local = 0;
        for (auto c: s) {
            if (c == 'E') local++;  else local--;
            res = max(res, local);
        }
        return res;
    }
};