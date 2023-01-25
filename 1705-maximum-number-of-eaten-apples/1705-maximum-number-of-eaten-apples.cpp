// class Solution {
// public:
//     int eatenApples(vector<int>& a, vector<int>& d, int res = 0, int to = 0) {
//         unordered_map<int, int> preSum;
//         for (int i = 0; i < a.size(); i++) {
//             preSum[i] += a[i];
//             preSum[i + d[i]] -= a[i];
//             to = max(to, i + d[i]);
//         }
//         for (int index = 0, currhave = 0; index <= to; index++) {
//             if (preSum.count(index)) currhave = max(currhave + preSum[index], 0);
//             cout<<index<<" - "<<currhave<<endl;
//             if (currhave > 0) res++, currhave--;
//         }
//         return res;
//     }
// };

class Solution {
public:
    typedef pair<int, int> P;
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans = 0, n = apples.size();
        priority_queue<P, vector<P>, greater<P>> que;
        int i = 0;
        while(i < n || que.size()) {
            if (i < n && apples[i] > 0) que.push({i + days[i] - 1, apples[i]});
            while (que.size() && que.top().first < i) que.pop();
            if (que.size()) {
                auto p = que.top();
                que.pop();
                if (p.second > 1) que.push({p.first, p.second - 1});
                ++ans;
            }
            ++i;
        }
        return ans;
    }
};