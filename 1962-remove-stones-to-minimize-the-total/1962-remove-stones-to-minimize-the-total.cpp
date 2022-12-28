class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        long long int sum = accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> pq(piles.begin(), piles.end());
        while (k--) {
            auto top = pq.top(); pq.pop();
            auto substract = top >> 1;
            sum -= substract;
            pq.push(top - substract);
        }
        return sum;
    }
};