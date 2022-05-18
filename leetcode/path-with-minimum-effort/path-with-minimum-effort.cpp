class Solution {
    struct PointWeight {
        int x; int y; int weight;
        PointWeight(int x, int y, int weight): x(x), y(y), weight(weight) {};
    };
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int row = size(heights);
        int column = size(heights[0]);
        int visited[101][101] = {0};
        
        auto comp = [](const PointWeight &a, const PointWeight &b) {
            return a.weight > b.weight;
        };
        
        auto isValidTo = [row, column]
            (pair<int, int> direction, pair<int, int> pos) {
      
            if (pos.first + direction.first >= row) return false;
            if (pos.first + direction.first < 0) return false;
            
            if (pos.second + direction.second >= column) return false;
            if (pos.second + direction.second < 0) return false;
            return true;
        };
        
        vector<pair<int, int>> directions = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
        int result = INT_MIN;
        
        priority_queue<PointWeight, vector<PointWeight>, decltype(comp)> q(comp);
        q.emplace(0, 0, 0);
        
        while(size(q)) {
            auto top = q.top();
            q.pop();
            
            if (visited[top.x][top.y]) continue;
            visited[top.x][top.y] = 1;
            
            result = max(result, top.weight);
            if (top.x == row - 1 && top.y == column - 1) return result;
            
            for(auto direction: directions) {
                if (isValidTo(direction, make_pair(top.x, top.y))) {
                    int newPosX = top.x + direction.first;
                    int newPosY = top.y + direction.second;
                    int absWeight = abs(heights[newPosX][newPosY] 
                                        - heights[top.x][top.y]); 
                    
                    q.emplace(newPosX, 
                              newPosY,
                              absWeight);
                }
            }
        }
        return result;
    }
};