// class Solution {
// public:
//     int minimumRecolors(string blocks, int k) {
//         int blackCount = 0, i;
//         for (i = 0; i < k; i++) if (blocks[i] == 'B') blackCount++;        
//         int res = k - blackCount;
//         while (i < blocks.size()) {
//             if (blocks[i] == 'B') blackCount++;
//             if (blocks[i - k] == 'B') blackCount--;
//             res = min(res, k - blackCount);
//             i++;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int b = 0, mb = 0;
        for (int i = 0; i < blocks.size(); ++i) {
            b += blocks[i] == 'B';
            if (i >= k) b -= blocks[i - k] == 'B';
            mb = max(b, mb);
        }
        return k - mb;
    }
//     int minimumRecolors(string blocks, int k) {
//         int w = 0, minW = INT_MAX;
//         for (int i = 0; i < blocks.size(); i++) {
//             w += blocks[i] == 'W';
//             if (i >= k) {
//                 w -= blocks[i-k] == 'W';
//                 minW = min(minW, w);
//                 cout<<minW<<endl;
//             }
//         }

//         return minW;
//     }
};


/*
int minimumRec olors(string blocks, int k) {
    int b = 0, mb = 0;
    for (int i = 0; i < blocks.size(); ++i) {
        b += blocks[i] == 'B';
        if (i >= k)
            b -= blocks[i - k] == 'B';
        mb = max(b, mb);
    }
    return k - mb;
}

"BBBBBWWBBWBWBWWWBWBWBBBBWBBBB
 WBWBWBWBWWBWWBWBWWWWBBWWWWBWW
 WWBWBBWBBWBBWWW"

*/