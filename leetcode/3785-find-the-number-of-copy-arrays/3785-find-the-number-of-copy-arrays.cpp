class Solution {
public:
    // int countArrays(vector<int>& O, vector<vector<int>>& B) {
    //     vector<int> dist;
    //     for (int i = 1; i < O.size(); i++) dist.push_back(O[i] - O[i-1]);
    //     int res = 0;
    //     bool got = true;
    //     for (auto from = B.front().front(); from <= B.front().back() && (!res || got); from++) {
    //         got = true;
    //         for (int j = 1, l = 0, now = from; j < B.size(); j++) {
    //             now += dist[l++];
    //             if (now < B[j][0] || B[j][1] < now) { got = false; break; }
    //         }
    //         if (got) res++;
    //     }
    //     return res;
    // }

    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int low = bounds[0][0], high = bounds[0][1], ans = high - low + 1;
        for(int i = 1; i < original.size(); ++i){
            int diff = original[i] - original[i-1];
            low = max(low + diff, bounds[i][0]);
            high = min(high + diff, bounds[i][1]);
            ans = min(ans, high - low + 1);
        }
        return ans < 0? 0: ans;
    }
};
