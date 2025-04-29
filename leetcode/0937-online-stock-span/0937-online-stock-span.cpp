class StockSpanner {
    vector<pair<int, int>> c;
public:
    StockSpanner() {}
    
    int next(int p) {
        int res = 1;
        while (c.size() && c.back().first <= p) {
            auto [_, i] = c.back(); c.pop_back();
            res += i;
        }
        c.push_back({p, res});
        return res;
    }
};