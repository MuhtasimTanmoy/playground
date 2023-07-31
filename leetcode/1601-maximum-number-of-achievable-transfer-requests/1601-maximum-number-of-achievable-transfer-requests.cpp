class Solution {
public:
    // int maximumRequests(int n, vector<vector<int>>& requests) {
    //     vector<int> track(n);
    //     for (auto r: requests) {
    //         auto from = r[0], to = r[1];
    //         track[from]--;
    //         track[to]++;
    //     }
    //     auto total = requests.size();
    //     int sum = 0;
    //     for (auto t: track)
    //         if (t > 0)
    //             sum += t;
    //     return total - sum;
    // }
    
    int bal[21] = {};
    int maximumRequests(int n, vector<vector<int>>& reqs, int i = 0) {
        if (i == reqs.size())
            return count(begin(bal), begin(bal) + n, 0) == n ? 0 : INT_MIN;
        --bal[reqs[i][0]];
        ++bal[reqs[i][1]];
        auto take = 1 + maximumRequests(n, reqs, i + 1);
        ++bal[reqs[i][0]];
        --bal[reqs[i][1]];
        return max(take, maximumRequests(n, reqs, i + 1));
    }
};