// 3000, 0 - > 2

class RecentCounter {
    vector<int> pingTimeline;
public:
    RecentCounter() {  }
    int ping(int t) {
        pingTimeline.push_back(t);
        auto notIn = lower_bound(pingTimeline.begin(), 
                                 pingTimeline.end(), 
                                 t - 3000) - pingTimeline.begin();
        return pingTimeline.size() - notIn;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */