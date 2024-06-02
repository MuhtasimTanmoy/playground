class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        set<int> bag;
        for (auto point: points) bag.insert(point.front());
        int res = 0, upto = -1;
        for (auto now: bag)
            if (now > upto) 
                res++, upto = now + w;
        return res;
    }
};