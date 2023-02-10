class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k, long long res = 0) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        while (k-- && pq.size()) {
            auto val = pq.top(); pq.pop();
            pq.push(sqrt(val));
        }
        while (pq.size()) res += pq.top(), pq.pop();
        return res;
    }
};