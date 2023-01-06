class Solution {
public:
    int totalMoney(int n) {
        int start = 1, ans = 0, prev = 1;
        for (int i = 1; i <= n; i++) {
            ans += start++;
            if (i % 7 == 0) start = ++prev;
        }
        return ans;
    }
};