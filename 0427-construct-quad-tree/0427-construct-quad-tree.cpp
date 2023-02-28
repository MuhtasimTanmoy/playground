/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        function<Node*(int, int, int)> go = [&](auto x, auto y, auto len) {
            auto val = grid[x][y];
            for (int i = x; i < x + len; i++)
                 for (int j = y; j < y + len; j++) 
                     if (grid[i][j] != val) {
                         auto half = len >> 1;
                         auto topLeft = go(x, y, half);
                         auto topRight = go(x , y + half, half);
                         auto bottomLeft = go(x + half, y, half);
                         auto bottomRight = go(x + half, y + half, half);
                         return new Node(val, false,
                                         topLeft, topRight,
                                         bottomLeft, bottomRight);
                     }
            return new Node(val, true);
        };
        return go(0, 0, grid.size());
    }
};