class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& r) {
        auto get = [](int w, int h) { return (double) w / h; };
        sort(r.begin(), r.end(), [&](const vector<int>& a, const vector<int>& b) {
            return get(a[0], a[1]) < get(b[0], b[1]);
        });
        
        long long res = 0, calc = 1;
        for (int i = 1; i < r.size(); i++) {
            auto ratioA = get(r[i][0], r[i][1]),
                 ratioB = get(r[i - 1][0], r[i - 1][1]);
            if (ratioA == ratioB) res += calc,  calc++; else calc = 1;
        }
        return res;
    }
};