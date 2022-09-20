class Solution {
public:
     bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      
        if(nums.size() < 2 || k <= 0) {
             return false;
         }
         
        vector<pair<long long,long long>> indexedNums;
      
        for(int i=0; i<nums.size(); i++) {
            indexedNums.push_back(make_pair(nums[i], i));
        }
      
        sort(indexedNums.begin(), indexedNums.end());
      
        for( int i = 1 ; i < nums.size(); i++ ) {
            
            for( int j = i - 1 ; j >= 0; j-- ) {
                
               if (abs(indexedNums[i].first - indexedNums[j].first) <= t) {
                    if (abs(indexedNums[i].second - indexedNums[j].second) <= k) {
                            return true;
                        }
                    } else {
                   break;
               }
                }
        }
                
        return false;
    }
};