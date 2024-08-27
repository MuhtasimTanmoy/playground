class Solution {
public:
    // vector<int> survivedRobotsHealths(vector<int>& positions, 
    //                                   vector<int>& healths, 
    //                                   string dirs) {
    //     vector<int> res;
    //     vector<pair<int, char>> stk;
    //     for (auto i = 0; i < positions.size(); i++) 
    //         if (stk.size()) {
    //             bool insert = false;
    //             while (stk.size()) {
    //                 auto last_dir = stk.back().second;
    //                 auto val = stk.back().first;
    //                 if (last_dir != dirs[i]) {
    //                     if (val == healths[i]) {
    //                         stk.pop_back();
    //                         break;
    //                     } else if (val < healths[i]) healths[i]--, insert = true;
    //                     else stk.back().second--;
    //                 } else {
    //                     stk.push_back({healths[i], dirs[i]});
    //                     break;
    //                 }
    //             }
    //             if (insert) stk.push_back({healths[i], dirs[i]});
    //         } else if (dirs[i] == 'L') res.push_back(healths[i]);
    //     for (auto i: stk) res.push_back(i.first);
    //     return res;
    // }
    
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& h, string directions) {
        int n = positions.size();
        vector<int> ind(n), stack, res;
        for (int i = 0; i < n; i++) ind[i] = i;
        sort(ind.begin(), ind.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });
        
        for (int i : ind) 
            if (directions[i] == 'R') 
                stack.push_back(i);
            else {
                while (stack.size() && h[i] > 0) 
                    if (h[stack.back()] < h[i]) 
                        h[stack.back()] = 0, stack.pop_back(),
                        h[i] -= 1;
                    else if (h[stack.back()] > h[i]) 
                        h[stack.back()] -= 1,
                        h[i] = 0;
                    else 
                        h[stack.back()] = 0, stack.pop_back(),
                        h[i] = 0;
            }
        
        for (int v : h) 
            if (v > 0) 
                res.push_back(v);
        return res;
    }
};


