class Solution {
    
    struct NumRange {
        int count;
        int start;
        int end;
        
        // NumRange(int n,int s, int e): count(n), start(s), end(e) {} 
    };
    
public:
    int findShortestSubArray(vector<int>& nums) {
        
        unordered_map<int, NumRange> map;
        
        int maxcnt = 1, mindis = 1;
        
        for (int i = 0; i < nums.size(); ++i) {
            
            int curr = nums[i];
            
            if (!map.count(curr))
                map[curr] = { 1, i, i };
            else {
                
                map[curr].end = i;
                
                if (++map[curr].count > maxcnt) {
                    
                    maxcnt = map[curr].count;
                    mindis = map[curr].end - map[curr].start + 1;
                    
                } else if (map[curr].count == maxcnt) 
                    mindis = min(mindis, map[curr].end - map[curr].start + 1);
            }
            
        }
        return mindis;
    }
};