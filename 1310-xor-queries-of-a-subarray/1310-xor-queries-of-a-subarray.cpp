class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res, preArr(arr.size() + 1);
        for (int i = 1; i < preArr.size(); i++) 
            preArr[i] = preArr[i-1] ^ arr[i-1];
        for (auto query: queries) {
            auto left = query[0], right = query[1] + 1;
            res.push_back(preArr[left] ^ preArr[right]);
        }
        return res;
    }
};