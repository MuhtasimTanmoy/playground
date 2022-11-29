class Solution {
public:
    int countTriples(int n) {
        vector<bool> squares(n * n + 1);
        for (int i = 1; i <= n; ++i) squares[i * i] = true;
        int res = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = i; i * i + j * j <= n * n; ++j)
                res += squares[i * i + j * j] * 2;
        return res;
    }
};