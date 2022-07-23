class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue<double> pq;
        long double s = 0;
        for(auto i: nums) {
            pq.push(i);
            s += i;
        }
        long double half = s / 2.0;
        long double sum = 0;
        int cnt = 0;
        while(!pq.empty()) {
            long double t = pq.top();
            pq.pop();
            sum += t / 2.0;
            cnt++;
            if(sum >= half) return cnt;
            pq.push(t / 2.0);
        }
        return cnt;
    }
};