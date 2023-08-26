class Solution {
public:
    long long maxRunTime(int n, vector<int>& bat) {
        long long sum = accumulate(begin(bat), end(bat), 0LL);
        priority_queue<int> pq(begin(bat), end(bat));
        while (pq.top() > sum / n) 
            sum -= pq.top(), 
            pq.pop(),
            --n;
        return sum / n;
    }
};