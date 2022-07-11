class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        auto comp = [&nums1, &nums2](pair<int,int> &a, pair<int,int>&b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(comp)> que(comp);
        que.push({0,0});
        
        vector<vector<int>> res;
        
        while (que.size() && k--) {
            auto now = que.top();
            res.push_back({nums1[now.first], nums2[now.second]});
            que.pop();
            
            if (!now.first && now.second+1 < nums2.size()) que.push({now.first, now.second+1});
            if (now.first+1 < nums1.size()) que.push({now.first+1, now.second});
        }
        return res;
    }
};