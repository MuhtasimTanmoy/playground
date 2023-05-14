class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        vector<int> res;
        for (int i = 0; i < obs.size(); i++) 
            if (res.empty() || res.back() <= obs[i]) {
                res.push_back(obs[i]);
                obs[i] = res.size();
            } else {
                auto elem = upper_bound(res.begin(), res.end(), obs[i]);
                *elem = obs[i];
                obs[i] = elem - res.begin() + 1;
            }
        return obs;
    }
};