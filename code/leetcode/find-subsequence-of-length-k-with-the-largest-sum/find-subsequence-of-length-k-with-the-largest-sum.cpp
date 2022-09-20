class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        vector<pair<int,int>> numWithIndex(size(nums));
        for(int i = 0; i < size(nums); i++) numWithIndex[i] = {nums[i], i};
        
        partial_sort(begin(numWithIndex), 
                     begin(numWithIndex) + k, 
                     end(numWithIndex),
                     [](auto &left, auto &right) {
            return left.first > right.first;
        });
        
        vector<int> result;
        sort(begin(numWithIndex), 
             begin(numWithIndex) + k, 
             [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });
        
        for (int i = 0; i < k; i++ ) result.push_back(numWithIndex[i].first);       
        return result;
    }
};