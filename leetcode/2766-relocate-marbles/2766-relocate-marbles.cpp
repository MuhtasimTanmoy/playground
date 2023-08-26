class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, 
                                vector<int>& from, 
                                vector<int>& to) {
        set<int> s(begin(nums), end(nums));
        for (int i = 0; i < from.size(); ++i) 
            s.erase(s.find(from[i])),
            s.insert(to[i]);
        return vector<int>(begin(s), end(s));
    }
};