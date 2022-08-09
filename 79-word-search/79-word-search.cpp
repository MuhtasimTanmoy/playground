// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
//         function<bool(int, int, int)> go = [&](int i, int j, int index) -> bool {
//             visited[i][j] = true;
//             if (board[i][j] != word[index]) return false;
//             if (index == word.size() - 1) return true;
//             bool res = false;
            
//             vector<pair<int, int>> directions = {{i+1, j}, {i, j+1}, {i-1, j}, {i, j-1}};
//             for (auto [x,y]: directions)
//                 if (x >= 0 
//                     && x < board.size() 
//                     && y >= 0 
//                     && y < board[0].size() 
//                     && !visited[x][y]) {
//                         auto isValid = go(x, y, index + 1);
//                         if (!isValid) visited[x][y] = false;
//                         res = res || isValid;
//                 }
//             return res;
//         };
        
//         for (int i = 0; i < board.size(); i++) 
//             for (int j = 0; j < board[0].size(); j++) 
//                 if (board[i][j] == word[0]) {
//                     for (auto &v: visited) fill(v.begin(), v.end(), false);
//                     if (go(i, j, 0)) return true;
//                 }
//         return false;
//     }
// };


class Solution {
public:
    bool search(vector<vector<char>>& b, string& w,int i,int j,int k,int& m,int& n){
        if(k==w.size()) return true;
        if(i==m || j==n || i<0 || j<0 || b[i][j]!=w[k]) return false;
        char c=b[i][j];
        b[i][j]='*';
        if(search(b,w,i,j+1,k+1,m,n)) return true;
        if(search(b,w,i+1,j,k+1,m,n)) return true;
        if(search(b,w,i,j-1,k+1,m,n)) return true;
        if(search(b,w,i-1,j,k+1,m,n)) return true;
        b[i][j]=c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(search(board,word,i,j,0,m,n))
                        return true;
                }
            }
        }
        return false;
    }
};