class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int limit = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        limit = k;
        for (auto n: nums) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > limit) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */