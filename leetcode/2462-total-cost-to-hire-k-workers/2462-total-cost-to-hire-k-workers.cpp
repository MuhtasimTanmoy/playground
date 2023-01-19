// class Solution {
// public:
//     long long totalCost(vector<int>& costs, int k, int candidates, long long res = 0) {
//         int left = candidates, right = costs.size() - candidates;
//         cout<<left<<" - "<<right<<endl;
//         if (left >= right) {
//             cout<<"go"<<endl;
//             sort(costs.begin(), costs.end());
//             return accumulate(costs.begin(), costs.begin() + k, 0);
//         }
        
//         priority_queue<int, vector<int>, greater<int>> 
//             lq(costs.begin(), costs.begin() + left), 
//             rq(costs.begin() + right, costs.end());
        
//         while (k--) {
//             auto minFromLeft = lq.top(), minFromRight = rq.top();
//             if (minFromLeft <= minFromRight) {
//                 res += minFromLeft;
//                 lq.pop();
//                 if (left <= right) lq.push(costs[left++]);
//             } else {
//                 res += minFromRight;
//                 rq.pop();
//                 if (left <= right) rq.push(costs[right--]);
//             }
//         }
//         return res;
//     }
// };

typedef pair<int,int> idxnum;
class Solution {
public:
    long long totalCost(vector<int>& cst, int k, int c) {
        int n = cst.size();
        long long res = 0;
        int l = min(c, n / 2), r = max(n-c, n / 2);
        
        priority_queue<idxnum,vector<idxnum>,greater<idxnum>> pq;
        for (int i = 0; i < l; ++i) pq.emplace(cst[i], i);
        for (int i = r; i < n; ++i) pq.emplace(cst[i], i);
        for (int j = 0; j < k; ++j) {
            auto[cost, i] = pq.top(); pq.pop();
            if (i < l) i = l++; 
            if (i >= r) i = --r; 
            if (l <= r) pq.emplace(cst[i], i);
            res += cost;
        }
        return res;
    }
};