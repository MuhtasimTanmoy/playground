class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        priority_queue<int> pq;
        unordered_map<int, int> counter;
        for (auto num: nums) counter[num]++;
        for (auto [_, count]: counter) pq.push(count);

        while (pq.size() > 1) {
            auto one = pq.top(); pq.pop(); 
            auto second = pq.top(); pq.pop();
            if (--one) pq.push(one);
            if (--second) pq.push(second);
        }

        return pq.size() ? pq.top(): 0;
    }
};