class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> mp;
        for(auto i : logs) {
            mp[i[0]]++;
            mp[i[1]]--;
        }
        int ans = 0, sum = 0;
        int res = 0;
        for (auto i : mp) {
            sum += i.second;
            if (sum > ans) {
                res = i.first;
                ans = sum;
            }
        }
        return res;
    }
};