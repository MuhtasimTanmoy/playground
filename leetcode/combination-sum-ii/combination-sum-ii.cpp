class Solution {
    
    vector<vector<int>> results;
    
    void traverse(vector<int>& candidates, int index, 
                  int target, vector<int>& result) {
        
        if (target < 0 ) return;
        
        if (target == 0) {
            results.push_back(result);
            return;
        }
        
        for(int i = index; i < size(candidates); i++) {
            
            if (i > index && candidates[i] == candidates[i-1]) {
                continue;
            }
            
            result.push_back(candidates[i]);
            traverse(candidates, i + 1, target - candidates[i], result);
            result.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> result;
        sort(candidates.begin(), candidates.end());
        
        traverse(candidates, 0, target, result);
        return results;
    }
};