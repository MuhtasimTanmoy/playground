class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& B) {
        for (auto i = 0; i < B.size(); i++)
            for (int j = B.back().size() - 1, r = j; j >= 0; j--)
                if (B[i][j] == '#') {
                    while (r > j && B[i][r] != '.') r--;
                    if (r > j) swap(B[i][j], B[i][r--]);
                } else if (B[i][j] == '*') r = j - 1;
        vector<vector<char>> res;
        for (auto i = 0; i < B.back().size(); i++) {
            res.push_back({});
            for (int j = B.size() - 1; j >= 0; j--) 
                res.back().push_back(B[j][i]);
        }
        return res;      
    }
};