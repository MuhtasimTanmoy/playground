// class Solution {
// public:
//     vector<int> restoreArray(vector<vector<int>>& ad_pairs) {
        
//         unordered_map<int, int> counter;
//         for (int i = 0; i < ad_pairs.size(); i++) {
//             counter[ad_pairs[i][0]]++;
//             counter[ad_pairs[i][1]]++
//         }
        
//         for (int i = 0; i < ad_pairs.size(); i++) {
//             counter[ad_pairs[i][0]]++;
//             counter[ad_pairs[i][1]]++
//         }
            
//         for (int i = 0; i < ad_pairs.size() - 1; i++)
//             for (int j = i + 2; j < ad_pairs.size(); j++) 
//                 for (auto l: ad_pairs[i])
//                     for (auto r: ad_pairs[j])
//                         if (l == r) 
//                             swap(ad_pairs[i+1], ad_pairs[j]);
        
//         deque<int> calc{ad_pairs[0][0]};
//         for (int i = 0; i < ad_pairs.size(); i++) {
//             auto first = ad_pairs[i][0], sec = ad_pairs[i][1];
//             if (calc.back() == first) calc.push_back(sec);
//             else if (calc.front() == first) calc.push_front(sec);
//             else if (calc.back() == sec) calc.push_back(first);
//             else if (calc.front() == sec) calc.push_front(first);
//         }
        
//         return vector<int>(calc.begin(), calc.end());
//     }
// };

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        unordered_map<int, vector<int>> ps;
        for (auto &p : adjacentPairs) {
            ps[p[0]].push_back(p[1]);
            ps[p[1]].push_back(p[0]);
        }
        
        vector<int> res;
        for (auto &p : ps) 
            if (p.second.size() == 1) {
                res.push_back(p.first);
                res.push_back(p.second[0]);
                break;
            }
        
        while (res.size() < adjacentPairs.size() + 1) {
            auto tail = res.back(), prev = res[res.size() - 2];
            auto &next = ps[tail];
            if (next[0] != prev) res.push_back(next[0]);
            else res.push_back(next[1]);
        }
        return res;
        
    }
};