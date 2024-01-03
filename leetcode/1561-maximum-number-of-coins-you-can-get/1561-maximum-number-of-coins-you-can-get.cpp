class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size(), res = 0;
        for (int i = n - 2, cnt = n / 3; cnt > 0; cnt--, i -= 2) 
            res += piles[i];
        return res;
    }
};