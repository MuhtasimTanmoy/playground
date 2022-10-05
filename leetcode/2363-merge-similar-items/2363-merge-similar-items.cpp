class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, 
                                          vector<vector<int>>& items2){
        vector<vector<int>> ans;
        map<int,int> m;
        for (auto a: items1) m[a[0]] = a[1] + m[a[0]];
        for (auto a: items2) m[a[0]] = a[1] + m[a[0]];
        for (auto a: m) ans.push_back({a.first,a.second});
        return ans;
    }
};