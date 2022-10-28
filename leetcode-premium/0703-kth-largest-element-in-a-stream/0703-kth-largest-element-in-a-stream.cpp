class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        pq = priority_queue<int, 
                            vector<int>, 
                            greater<int>>(nums.begin(), nums.end());
        limit = k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > limit) pq.pop();
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int limit;
};