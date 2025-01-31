class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int upto) {
        int n = nums.size();
        vector<int> res; k--;
        
        map<int, int> track;
        auto get_sum = [&]() {
            vector<pair<int, int>> r;
            for (auto [x, count]: track) r.emplace_back(count, x);
            sort(r.begin(), r.end(), greater<pair<int, int>>());
            
            int sum = 0;
            for (auto j = 0; j < min( (int) r.size(), upto); j++)  
                sum += r[j].first * r[j].second;
            return sum;
        };
        
        for (auto i = 0; i < n; i++) {
            track[nums[i]]++;
            if (i < k) continue;
            res.push_back(get_sum());
            track[nums[i - k]]--;
        }
        return res;
    }
};