class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int res = INT_MAX;
        for (int i = 0, black = 0, j = 0; i < blocks.size(); i++) {
            black += blocks[i] == 'B';
            if (i >= k) black -= blocks[j++] == 'B';
            if (i + 1 >= k) 
                res = min(res, k - black);
        }
        return res;
    }
};