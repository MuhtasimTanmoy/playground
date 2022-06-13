// Completely mis-calculated the result

// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int res = 0;
//         int prevIndex = 0;
        
//         for (auto stage: triangle) {
            
//             int n = size(stage);
//             int minInStage = INT_MAX;
//             int limit = min(n, prevIndex + 2);
            
//             for(int i = prevIndex; i < limit; i++) {
//                 if (stage[i] < minInStage) {
//                     minInStage = stage[i];
//                     prevIndex = i;
//                 }
//             }
            
//             cout<<minInStage<<endl;
//             res += minInStage;
//         }
        
//         return res;
//     }
// };

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i= n-2; i >= 0; i--) 
            for(int j = 0; j <= i; j++)
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            
        return triangle[0][0];
    }
};