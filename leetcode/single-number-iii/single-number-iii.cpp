class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int> result;
        map<int, int> occurenceCount;
        
        for( int i = 0; i < nums.size(); i++) {
            occurenceCount[nums[i]]+=1;
        }
        
        for( auto occurence: occurenceCount) {
            if (occurence.second == 1) {
                result.push_back(occurence.first);
            }
        }
        
        return result;
    }
};