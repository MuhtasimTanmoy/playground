class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;
        for(auto num: nums) map[num]++;
        
        int operations = 0;
        for(auto num: nums) 
            if (map[num] && map[k-num]) {
                map[num]--;
                map[k-num]--;
                if(map[num] >= 0) operations++;
            }
        
        return operations;
    }
};