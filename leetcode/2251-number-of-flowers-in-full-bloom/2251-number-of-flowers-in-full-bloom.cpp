class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, 
                                 vector<int>& persons) {
        vector<int> start, end;
        for(auto& t :flowers) start.push_back(t[0]), end.push_back(t[1]);
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        vector<int> res;
        for (auto t : persons) {
            auto s = upper_bound(start.begin(), start.end(), t) - start.begin(), 
                 e = lower_bound(end.begin(), end.end(), t) - end.begin();
            res.push_back(s - e);
        }
        return res;
    }
};