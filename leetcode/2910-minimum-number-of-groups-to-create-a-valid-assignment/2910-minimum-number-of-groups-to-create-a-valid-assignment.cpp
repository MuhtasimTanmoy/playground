class Solution {
public:
//     int minGroupsForValidAssignment(vector<int>& nums) {
        
//         unordered_map<int, int> counter;
//         for (auto num: nums) counter[num]++;
        
//         vector<int> count;
//         for (auto [val, c]: counter) count.push_back(c);
        
//         if (count.size() == 1) return 1;
//         sort(count.begin(), count.end());
        
//         for (auto c: count) cout<<c<<" ";
        
//         auto sec =  (count[1] + count[0]) / (count[0] + 1);
//         int group = 1 + sec;
        
//         for (int i = 2, min_count = count[0] + 1; i < count.size(); i++) 
//                 group += (count[i] + min_count - 1) / min_count;
//         return group;
//     }
    
    
    int check(vector<int> &counts, int g1, int g) {
        int groups = 0;
        for (int cnt : counts) {
            bool found = false;
            for (int p = cnt / g1; p >= 0 && !found; --p)
                if ((cnt - p * g1) % g == 0) {
                    groups += p + (cnt - p * g1) / g;
                    found = true;
                }
            if (!found)
                return INT_MAX;
        }
        return groups;
    }
    
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (auto n : nums)
            ++counter[n];
        vector<int> counts;
        for (auto [_, cnt] : counter)
            counts.push_back(cnt);
        sort(begin(counts), end(counts));
        for (int div = 1; counts[0] / div > 1; ++div) {
            int g = counts[0] / div;
            int res = min(check(counts, g + 1, g), check(counts, g, g - 1));
            if (res != INT_MAX)
                return res;
        }
        return check(counts, 2, 1);
    }
};