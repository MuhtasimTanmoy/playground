class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int blackCount = 0, i;
        for (i = 0; i < k; i++) if (blocks[i] == 'B') blackCount++;        
        int res = k - blackCount;
        while (i < blocks.size()) {
            if (blocks[i] == 'B') blackCount++;
            if (blocks[i - k] == 'B') blackCount--;
            res = min(res, k - blackCount);
            i++;
        }
        return res;
    }
};