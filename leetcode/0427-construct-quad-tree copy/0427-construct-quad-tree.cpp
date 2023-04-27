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
            auto isDiff = [&]() {
                for (int i = x; i < x + len; i++)
                    for (int j = y; j < y + len; j++) 
                        if (grid[i][j] != val) return true;
                return false;
            };
            if (isDiff()) {
                 auto l = len >> 1;
                 auto tl = go(x, y, l), tr = go(x , y + l, l);
                 auto bl = go(x + l, y, l), br = go(x + l, y + l, l);
                 return new Node(val, false, tl, tr, bl, br);
            }
            return new Node(val, true);
        };
        return go(0, 0, grid.size());
    }
};