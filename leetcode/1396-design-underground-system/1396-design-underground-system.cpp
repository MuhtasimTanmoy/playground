class UndergroundSystem {
    unordered_map<int, pair<string, int>> tracker;
    unordered_map<string, pair<double, int>> res;
    string make_key(string& a, string& b) { return a + "-" + b; };
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        tracker[id] = {stationName, t};
    }
    
    void checkOut(int id, string to, int t) {
        if (!tracker.count(id)) return;
        
        auto [name, start_time] = tracker[id];
        auto key = make_key(name, to);
        auto duration = t - start_time;
        
        if (res.count(key)) {
            auto [sum, count] = res[key];
            res[key] = { (sum * count + duration) / (count + 1), count + 1};
        } else
            res[key] = {duration, 1};
    }
    
    double getAverageTime(string from, string to) {
        auto key = make_key(from, to);
        return res[key].first;
    }
};