class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& I, vector<int>& Q) {
        sort(I.begin(), I.end());
        vector<int> max_so_far { I.front().back() };
        for (auto i = 1; i < I.size(); i++) 
            max_so_far.push_back(max(max_so_far.back(), I[i].back()));
        
        vector<int> res;
        for (auto q: Q) {
            auto i = upper_bound(I.begin(), I.end(), vector<int>{q, INT_MAX}) - I.begin();
            if (!i) res.push_back(0);
            else res.push_back(max_so_far[i-1]);
        }
        return res;
    }
};