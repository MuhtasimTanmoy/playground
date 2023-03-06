class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& n) {
        int len = n.size();
        vector<int> res(len, 0);
        
        for (int i = len - 1, prev = 0; i >= 0; i--) 
            res[i] = prev, 
            prev += n[i];
        
        for (int i = 0, prev = 0; i < len; i++)
            res[i] = abs(prev - res[i]),
            prev += n[i];
        
        return res;
    }
};