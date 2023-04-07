/*
class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, 
                                vector<int>& p, 
                                long long success) {
        vector<int> res;
        for (auto i: s) {
            int match = count_if(p.begin(), p.end(), [&](auto elem) {
                return 1LL * elem * i >= success;
            });
            res.push_back(match);
        }
        return res;
    }
};
*/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, 
                                vector<int>& p, 
                                long long success) {
        vector<int> res;
        sort(p.begin(), p.end());
        for (auto i: s) {
            auto find = (success + i - 1) / i;
            int match = p.end() - lower_bound(p.begin(), p.end(), find);
            res.push_back(match);
        }
        return res;
    }
};