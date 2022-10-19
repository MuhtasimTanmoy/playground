class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> li(1001, -1);
        for (auto item: arr2) li[item] = 0;
        for (auto &item: arr1) if (li[item] != -1) { li[item]++; item = -1; }
        
        vector<int> res;
        for (auto item: arr2) while(li[item]--) res.push_back(item);
        
        sort(arr1.begin(), arr1.end());
        for (auto &item: arr1) if(item != -1) res.push_back(item);
        return res;
    }
};