class Solution {
public:
    vector<int> getRow(int row) {
        if (!row) return {1};
        
        vector<int> prev;
        for (int r = 1; r <= row; r++) {
            vector<int> now {1};
            for (int i = 1; i < r; i++) now.push_back(prev[i] + prev[i-1]);
            now.push_back(1);
            swap(prev, now);
        }
        return prev;
    }
};