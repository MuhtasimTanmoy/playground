class Solution {
    
    struct PosWeight {
        pair<int, int> pos;
        int weight;
        
        PosWeight(pair<int, int> a, int weight): pos(a), weight(weight){}
        // bool operator<(const PosWeight& p1, const PosWeight& p2) {
        //     return p1.height < p2.height;
        // }
    };
    
    int visited[51][51] = {0};
    
    int traverse(vector<vector<int>>& grid) {
        int row = size(grid);
        int column = size(grid[0]);
        vector<pair<int, int>> directions = { {0,1}, {1,0}, {-1,0}, {0,-1} };

        auto isValidTo = [&grid, row, column]
            (pair<int, int> direction, pair<int, int> pos) {
      
            if (pos.first + direction.first >= row) return false;
            if (pos.first + direction.first < 0) return false;
            
            if (pos.second + direction.second >= column) return false;
            if (pos.second + direction.second < 0) return false;
            return true;
        };
            
        auto comp = [](PosWeight &a, PosWeight &b) {
            return a.weight > b.weight;
        };
        
        int maxx =INT_MIN;
        
        priority_queue<PosWeight, vector<PosWeight>, decltype(comp)> pq(comp);
        pq.emplace(make_pair(0,0), grid[0][0]);
        
        while(!pq.empty()) {
            auto elem = pq.top();
            pq.pop();
            
            if (visited[elem.pos.first][elem.pos.second]) continue;
            visited[elem.pos.first][elem.pos.second] = 1;
            
            maxx = max(maxx, elem.weight);
            if (elem.pos.first == row - 1 && elem.pos.second == column - 1) return maxx;
            
            for(auto direction: directions)
                if (isValidTo(direction, elem.pos)) {
                    pair<int,int> toGo = make_pair( direction.first + elem.pos.first, 
                                  direction.second + elem.pos.second );
                    auto weight = grid[toGo.first][toGo.second];
                    pq.emplace(toGo, weight);
                }
        }
        
        return maxx;
    }
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        return traverse(grid);
    }
};