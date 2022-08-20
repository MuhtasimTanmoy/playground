class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        pq.push(amount[0]);
        pq.push(amount[1]);
        pq.push(amount[2]);
        int count = 0;
        while(pq.top() != 0) {
            auto maxItem = pq.top(); pq.pop();
            if (!pq.empty()) {
                auto secMax = pq.top(); pq.pop();
                if (secMax) pq.push(secMax - 1);
            }
            pq.push(maxItem - 1);
            count++;
        }
        return count;
    }
};