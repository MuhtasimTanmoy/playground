// class Solution {
//     struct Point {
//         int x;
//         int y;
//         int weight;
        
//         Point(int x, int y, int weight): x(x), y(y), weight(weight) {}
//     }
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if (target > target) return false;
//         auto comp = [&](const Point& a, const Point& b) { return a.weight < b.weight; };
//         priority_queue<Point, vector<Point>, decltype(comp)> pq(comp);
//         pq.emplace_back(0, 0, 0);
        
//         vector<vector<int>> dir = {{0, 1}, {1, 0}, {1, }}
        
//         while(pq.size()) {
//             auto item = pq.top();
//             pq.pop();
            
//             if (matrix[item.x][item.y] == target) return true;
            
//         }
//     }
// };

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int r = 0, c = col - 1;
        
        while (r < row && c >= 0) {
            if (matrix[r][c] > target) --c;
            else if (matrix[r][c] < target) ++r;
            else return true;
        }
        
        return false;
    }
};
