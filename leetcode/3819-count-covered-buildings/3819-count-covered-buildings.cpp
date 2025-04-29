// class Solution {
// public:
//     int countCoveredBuildings(int n, vector<vector<int>>& B) {
//         if (B.size() < 5) return 0;
        
//         set<int> xx, yy;
//         int res = 0;
//         for (auto b: B) 
//             xx.insert(b.front()),
//             yy.insert(b.back());

//         auto x = vector<int>(xx.begin(), xx.end());  
//         auto y = vector<int>(yy.begin(), yy.end());  
//         if (x.size() < 3 || y.size() < 3) return 0; 

//         for (auto b: B) {
//             auto i = lower_bound(x.begin(), x.end(), b.front()) - x.begin(), 
//                  j = lower_bound(y.begin(), y.end(), b.back()) - y.begin();
            
//             cout<<i<<" - "<<j<<endl;

//             auto in_mid_x =  (i > 0 && i < x.size() - 1),
//                  in_mid_y =  (j > 0 && j < y.size() - 1);
            
//             if (in_mid_x && in_mid_y) res++;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> xMax(n + 1, INT_MIN), 
                    xMin(n + 1, INT_MAX), 
                    yMax(n + 1, INT_MIN), 
                    yMin(n + 1, INT_MAX);

        for (auto& b : buildings)
            xMax[b[1]] = max(xMax[b[1]], b[0]),
            xMin[b[1]] = min(xMin[b[1]], b[0]),
            yMax[b[0]] = max(yMax[b[0]], b[1]),
            yMin[b[0]] = min(yMin[b[0]], b[1]);

        int result = 0;
        for(auto& b : buildings)
            if (b[0] < xMax[b[1]] && b[0] > xMin[b[1]] &&
               b[1] < yMax[b[0]] && b[1] > yMin[b[0]])
                ++result;
                
        return result;
    }
};

