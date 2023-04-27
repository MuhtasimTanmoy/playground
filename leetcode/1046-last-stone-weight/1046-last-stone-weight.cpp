class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int> pq(s.begin(), s.end());
        while (pq.size() > 1) {
            auto one = pq.top(); pq.pop();
            auto two = pq.top(); pq.pop();
            auto to_be_inserted = one - two;
            if (to_be_inserted) pq.push(to_be_inserted);
        }
        return pq.size() ? pq.top(): 0;
    }
};