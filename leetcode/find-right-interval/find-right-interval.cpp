class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        // keep starValue with index
        map<int, int> bag;
        
        int itr = 0;
        for (auto interval: intervals) {
            bag[interval[0]] = itr;
            itr++;
        }
        
        vector<int> result;
        for (auto interval: intervals) {
             int key = interval[1];
             auto itr = bag.lower_bound(key);
             result.push_back(itr == bag.end() ? -1 : itr->second);
        }
        
        return result;
    }
};