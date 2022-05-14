class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        int res = 0;
        
        for ( int i = 0; i < n; i++ ) {
            
            if (informTime[i] == 0 ) { // he is leaf
                
                int j = i, t = 0;
                
                while (manager[j] != -1) {
                    t += informTime[manager[j]];
                    j = manager[j];
                }
                
                res = max(res, t);
            }
        }
        
        return res;
    }
};