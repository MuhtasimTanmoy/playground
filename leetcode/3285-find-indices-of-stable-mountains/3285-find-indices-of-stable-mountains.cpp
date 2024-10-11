class Solution {
public:
    vector<int> stableMountains(vector<int>& h, int thres) {
        vector<int> res;
        for (auto i = 1; i < h.size(); i++) 
            if (h[i - 1] > thres) 
                res.push_back(i);
        return res;
    }
};