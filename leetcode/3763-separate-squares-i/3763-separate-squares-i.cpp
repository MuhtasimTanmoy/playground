// // 910 / 915 testcases passed

// class Solution {
// public:
//     double separateSquares(vector<vector<int>>& S) {
//         // sort(S.begin(), S.end(), [](auto l, auto r) {
//         //     return l[1] < r[1];
//         // });

//         long long area = 0;
//         for (auto s: S) area += 1LL * s.back() * s.back();

//         double target = area / 2.0;
//         auto calc = [&](double m) {
//             double now = 0;
//             for (auto s: S) {
//                 if (s[1] < m) now += s.back() * min(m - s[1], (double) s.back());
//             }
//             return now;
//         };

//         double l = 0, r = INT_MAX;
//         for (auto i = 0; i < 50; i++) {
//             double m = l + (r - l) / 2;
//             auto area = calc(m);
//             if (area >= target) r = m; else l = m;
//         }
//         return r;
//     }
// };


class Solution {
public:
    double helper(double line, vector<vector<int>>& squares){
        double aAbove = 0, aBelow = 0;
        int n = squares.size();
        for(int i = 0; i < n; i++){
            int x = squares[i][0], y = squares[i][1];
            int l = squares[i][2];
            double total = (double) l * l;
            
            if(line <= y){
                aAbove += total;
            } 
            else if(line >= y + l){
                aBelow += total;
            } 
            else{
                 // The line intersects the square.
                double aboveHeight = (y + l) - line;
                double belowHeight = line - y;
                aAbove += l * aboveHeight;
                aBelow += l * belowHeight;
            }
        }
        return aAbove - aBelow;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double lo = 0, hi = 2*1e9;
        
        for(int i = 0; i < 60; i++){
            double mid = (lo + hi) / 2.0;
            double diff = helper(mid, squares);

            if(diff > 0) lo = mid;
            else hi = mid;
        }

        return hi;
    }
};