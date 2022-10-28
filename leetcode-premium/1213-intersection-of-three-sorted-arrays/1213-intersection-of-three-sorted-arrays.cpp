class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, 
                                   vector<int>& arr2, 
                                   vector<int>& arr3) {
        vector<int> counter(2001, 0);
        for (auto c: arr1) counter[c]++;
        for (auto c: arr2) counter[c]++;
        for (auto c: arr3) counter[c]++;
        vector<int> res;
        for (int i = 0; i < counter.size(); i++) 
            if (counter[i] == 3) 
                res.push_back(i);
        return res;
    }
};