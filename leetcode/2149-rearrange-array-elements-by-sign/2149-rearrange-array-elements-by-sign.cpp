class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        deque<int> p, n;
        vector<int> res;
        for (auto num: nums) {
            if (num > 0) p.push_back(num); else n.push_back(num);
            if (p.size() && n.size()) 
                res.push_back(p.front()), 
                p.pop_front(),
                res.push_back(n.front()), 
                n.pop_front();
        }
        return res;
    }
};