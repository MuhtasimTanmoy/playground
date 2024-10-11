class Solution {
public:
    int generateKey(int one, int two, int three) {
        int res = 0, multi = 1;
        while (one || two || three) {
            auto now = min({one % 10, two % 10, three % 10});
            res += now * multi;
            multi *= 10;
            one /= 10, two /= 10, three /= 10;
        }
        return res;
    }
};