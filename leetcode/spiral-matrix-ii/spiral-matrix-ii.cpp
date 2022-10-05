class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        enum Direction {leftToRight, upToDown, rightToLeft, downToUp};
        
        int rightMost = n-1;
        int downMost = n-1;
        int leftMost = 0;
        int upMost = 1;
        
        Direction current = leftToRight;
        auto directionProvider = [&] (int x, int y) -> pair<int, int> {
            
            if ( y == rightMost && current == leftToRight ) 
            { rightMost--; current = upToDown; }
            
            if ( x == downMost  && current == upToDown ) 
            { downMost--;  current = rightToLeft; }
            
            if ( y == leftMost && current == rightToLeft ) 
            { leftMost++;  current = downToUp; }
            
            if ( x == upMost && current == downToUp ) 
            { upMost++;  current = leftToRight; }
            
            if ( current == leftToRight ) { return {0,1}; }
            else if ( current == upToDown ) { return {1, 0}; }
            else if ( current == rightToLeft ) { return {0,-1}; }
            return {-1,0};
        };
        
        vector<vector<int>> result(n, vector<int> (n, 0));
        int iterationCount = n*n;
        
        pair<int, int> position = make_pair(0,0);
        for(int i = 1; i <= iterationCount; i++) {
            result[position.first][position.second] = i;
            auto vector = directionProvider(position.first, position.second);
            position.first += vector.first;
            position.second += vector.second;
        }
        return result;
    }
};