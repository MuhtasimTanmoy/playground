class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        auto is_set = [](int num, int at) -> bool { return num & (1 << at); };
        for (int i = 0; i < 32; i++) {
            auto should_set = is_set(c, i);
            if (should_set) {
                if (!is_set(a, i) && !is_set(b, i)) res++;
            } else 
                res += is_set(a, i) + is_set(b, i);
        }
        return res;
    }
};