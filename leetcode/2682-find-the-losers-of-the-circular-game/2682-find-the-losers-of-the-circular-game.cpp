class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> tracker(n), res;
        for (int i = 0, mul = 1; !tracker[i]; i = (i + mul * k) % n, mul++)
            tracker[i] = 1;
        for (int i = 0; i < tracker.size(); i++)
            if (!tracker[i])
                res.push_back(i + 1);
        return res;
    }
};