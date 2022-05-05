class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> bag;
        
        int count = 0;
        for(int i = 0; i < size(nums); i++ ) bag[nums[i]].push_back(i);
        
        for (auto &pair: bag) {
            auto list = pair.second;                
            for(int i = 0; i < size(list) - 1; i++ ) 
                for(int j = i + 1; j < size(list); j++ ) 
                    if ( (list[i] * list[j]) % k == 0 ) count++;            
        }
        return count;
    }
};