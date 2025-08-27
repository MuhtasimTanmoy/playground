class Solution {
public:
    int totalFruit(vector<int>& F) {
        map<int, int> keep;
        int len = 0;
        for (int l = 0, r = 0; r < F.size(); r++) {
            keep[F[r]]++;
            while (keep.size() > 2) {
                if (--keep[F[l]] == 0) keep.erase(F[l]);
                l++;
            }
            len = max(len, 
                keep.begin()->second + 
                (keep.size() == 1 ? 0: keep.rbegin()->second));
        }
        return len;
    }
};