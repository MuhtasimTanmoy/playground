class Solution {
    
    vector<vector<int>> result;
    void traverse(vector<int>& candidates, int index, 
                  int target, vector<int> sumArr) {
        
        if(target < 0 ) return;
            
        if ( target == 0 ) {
            result.push_back(sumArr);
            return;
        }
        
        for(int i = index; i < size(candidates); i++) {
            sumArr.push_back(candidates[i]);
            traverse(candidates, i, target-candidates[i], sumArr);
            sumArr.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sumArr;
        traverse(candidates, 0, target, sumArr);
        return result;
    }
};