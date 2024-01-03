class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;
    int max_s = 0;
public:
    SeatManager(int n) {}    
    int reserve() {
        int res = pq.empty() ? ++max_s : pq.top();
        if (pq.size()) pq.pop();
        return res;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};