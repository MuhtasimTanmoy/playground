class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        set<int> distinctNums(nums.begin(), nums.end());
        if ( distinctNums.size() < 3 ) return *(distinctNums.rbegin());
        
        auto itr = distinctNums.rbegin();
        int limit = 2;
        while(limit--) itr++;
        
        return *(itr);
    }
};