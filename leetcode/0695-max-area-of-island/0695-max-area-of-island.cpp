class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& G) {
        int maxArea = 0;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        function<int(int, int)> check = [&](int i, int j) -> int {
            G[i][j] = -1;
            int res = 1;
            for(auto direction: directions) {
                auto nextX = i + direction[0], nextY = j + direction[1];
                if (nextX >= 0 && nextY >= 0 
                    && nextX < size(G) && nextY < size(G[0])
                    && G[nextX][nextY] == 1) 
                        res += check(nextX, nextY);
            }
            return res;
        };
        
        for (int i = 0; i < size(G); i++)
            for (int j = 0; j < size(G[0]); j++) 
                if (G[i][j] == 1) 
                    maxArea = max(check(i, j), maxArea);
        return maxArea;
    }
};