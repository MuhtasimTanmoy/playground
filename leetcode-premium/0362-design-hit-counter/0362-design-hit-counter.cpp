class HitCounter {
    const int LIMIT = 300;
    queue<int> q;
public:
    HitCounter() {}
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while(q.size() && q.front() <= timestamp - LIMIT) q.pop();
        return q.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */