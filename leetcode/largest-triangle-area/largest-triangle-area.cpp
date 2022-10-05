class Solution {
    public:

    double Area(vector<int> A, vector<int> B, vector<int> C) {
         return (double)abs(A[0]*(B[1]-C[1]) + B[0]*(C[1]-A[1]) + C[0]*(A[1]-B[1]))/2;
    }

    double largestTriangleArea(vector<vector<int>>& points)  {
        int n = points.size();
        double maxarea = INT_MIN;
        for(int i=0 ; i<n-2 ; ++i) {
            for(int j=i ; j<n-1 ; ++j) {
                for(int k=j ; k<n ; ++k) {
                    maxarea = max(maxarea, Area(points[i],points[j],points[k]));
                }
            }
        }
    
        return maxarea;
    }
};

// class Solution {
// public:
//     double largestTriangleArea(vector<vector<int>>& points) {        
//         int lowX, lowY = INT_MAX;
//         int hiX, hiY = INT_MIN;
//         for(auto point: points) {
//             lowX = min(point[0], lowX);
//             lowY = min(point[1], lowY);
            
//             hiX = max(point[0], hiX);
//             hiY = max(point[1], hiY);
//         }
//         auto area = ( ( hiX - lowX ) * ( hiY - lowY ) );
//         double ans = area / 2.0;
//         return ans;
//     }
// };