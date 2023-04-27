class Solution {
public:
    // int minTaps(int n, vector<int>& ranges) {
    //     vector<pair<int, int>> p;
    //     for (int i = 0; i < ranges.size(); i++) {
    //         auto l = max(0, i - ranges[i]), r = min(n, i + ranges[i]);
    //         p.push_back({l, r});
    //     }
    //     function<int(int, int)> go = [&](auto idx, auto covered_upto) -> int {
    //         if (idx == p.size() || covered_upto == n) return 0;
    //         auto now = p[idx];
    //         if (now.first > covered_upto) return INT_MAX;
    //         auto taken = now.second ? 1 + go(idx + 1, idx + now.second): INT_MAX,
    //              not_taken = go(idx + 1, covered_upto);
    //         return min(taken, not_taken);
    //     };
    //     auto ans = go(0, 0);
    //     return ans >= INT_MAX ? -1: ans;
    // }
    
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jumps(n + 1, 0);
        
        for (int i = 0; i < ranges.size(); i++) {
            int l = max(0, i - ranges[i]);
            int r = min(n, i + ranges[i]);
            jumps[l] = max(jumps[l], r - l);
        }
        
        int count = 0, curEnd = 0, curFarthest = 0;
        for (int i = 0; i < jumps.size() - 1; i++) {
            if (i > curFarthest) return -1;
            curFarthest = max(curFarthest, i + jumps[i]);
            
            if (i == curEnd) 
                count++, curEnd = curFarthest;
        }
        
        return curFarthest >= n ? count : -1;
    }
};