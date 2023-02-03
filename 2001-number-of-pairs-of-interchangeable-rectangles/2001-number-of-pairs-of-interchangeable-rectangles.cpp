class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        auto get = [](int w, int h) { return (double) w / h; };
        sort(rectangles.begin(), rectangles.end(), 
             [&](const vector<int>& a, const vector<int>& b) {
            return get(a[0], a[1]) < get(b[0], b[1]);
        });
        
        long long res = 0, calc = 1;
        for (int i = 1; i < rectangles.size(); i++)
            if (get(rectangles[i][0], rectangles[i][1]) == 
                get(rectangles[i - 1][0], rectangles[i - 1][1])) {
                res += calc;
                calc++;
            } else 
                calc = 1;
        return res;
    }
};