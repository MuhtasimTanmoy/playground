class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        unordered_set<int> bag;
        
        for(auto row: matrix) {
            for(auto col: row) {
                if (bag.count(col)) return false;
                bag.insert(col);
            }
            bag.clear();
        }

        bag.clear();

        for(int j = 0; j < matrix[0].size(); j++) {
            for(int i = 0; i < matrix.size(); i++) {
                if (bag.count(matrix[i][j])) return false;
                bag.insert(matrix[i][j]);
            }
            bag.clear();
        }
        
        return true;
    }
};