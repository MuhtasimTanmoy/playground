class Solution {
public:
    // vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
    //     vector<long long> res;
    //     multiset<long long> ms;
    //     unordered_map<int, long long> counter;
    //     for (auto i = 0; i < nums.size(); i++) {
    //         auto prev = counter[nums[i]];
    //         if (ms.count(prev)) ms.erase(ms.find(prev));
    //         counter[nums[i]] = max(counter[nums[i]] + freq[i], 0LL);
    //         ms.insert(counter[nums[i]]);
    //         res.push_back(*ms.rbegin());
    //     }
    //     return res;
    // }
    
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<long long> res;
        priority_queue<pair<long long, long long>> ms;
        unordered_map<int, long long> counter;
        for (auto i = 0; i < nums.size(); i++) {
            counter[nums[i]] += freq[i];
            ms.push({counter[nums[i]], nums[i]});
            while (counter[ms.top().second] != ms.top().first) ms.pop();
            res.push_back(ms.top().first);
        }
        return res;
    }
};