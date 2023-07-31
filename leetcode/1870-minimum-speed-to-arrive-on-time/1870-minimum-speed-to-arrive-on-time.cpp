class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        auto l = 1, r = 10000001;
        
        auto calc = [&](double target) {
            double res = 0, n = dist.size();
            for (auto i = 0; i < n - 1; i++) res += ceil(1.0 * dist[i] / target);
            res += dist[n - 1] / target;
            return res;
        };
        
        double time_taken = 0;
        while (l < r) {
            auto m = l + (r - l) / 2;
            time_taken = calc(m);
            if (time_taken <= hour) r = m; else l = m + 1;
        }
        return l == 10000001 ? -1 : l;
    }
};