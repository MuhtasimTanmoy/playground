// class Solution {
//     vector<vector<int>> result;
    
//     void traverse(int now, int limit, int count, vector<int> curr) {
//         if (count == 0) {
//             result.push_back(curr);
//             return;
//         }
        
//         if (now > limit) return;
        
//         curr.push_back(now);
//         traverse(now + 1, limit, count-1, curr);
//         curr.pop_back();
//         traverse(now + 1, limit, count, curr);
//     }
    
// public:
//     vector<vector<int>> combine(int n, int k) {
//         vector<int> curr;
//         traverse(1, n, k, curr);
//         return result;
//     }
// };

class Solution {
    vector<vector<int>>  res;
    void recurse( vector<vector<int>> &res, int begin, 
                 int n, int k, vector<int> &currSoln) {
        
        if(k == 0) {
            res.push_back(currSoln);
            return;
        }
        
        for(int i = begin; i <= n-k+1; i++) {    
            currSoln.push_back(i);       
            recurse(res, i+1, n, k-1, currSoln);
            currSoln.pop_back();
        }
    }
    
    public:
    vector<vector<int>> combine(int n, int k) {                
        vector<int> currSoln;                   
        recurse(res, 1, n, k, currSoln);
        return res;
    }
};