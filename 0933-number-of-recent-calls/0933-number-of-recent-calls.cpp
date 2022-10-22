// log(n)
// class RecentCounter {
//     vector<int> pingTimeline;
// public:
//     RecentCounter() {  }
//     int ping(int t) {
//         pingTimeline.push_back(t);
//         auto notIn = lower_bound(pingTimeline.begin(), 
//                                  pingTimeline.end(), 
//                                  t - 3000) - pingTimeline.begin();
//         return pingTimeline.size() - notIn;
//     }
// };

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() { }
    int ping(int t) {
        q.push(t);
        while(q.front() < t - 3000) q.pop();
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */