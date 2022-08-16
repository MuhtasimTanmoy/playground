class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        int score = 0;
        pq.push(a); pq.push(b); pq.push(c);
        while (!pq.empty()) {
            auto topMost = pq.top(); pq.pop();
            if (pq.empty()) break;
            auto secondMost = pq.top(); pq.pop();
            if (topMost - 1) pq.push(topMost - 1); 
            if (secondMost - 1) pq.push(secondMost - 1);
            score++;
        }
        return score;
    }
};