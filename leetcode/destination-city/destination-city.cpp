class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> cantBe;
        
        for(auto &path: paths) 
            cantBe.insert(path[0]);
        
        
        for(auto &path: paths) 
            if (!cantBe.count(path[1])) return path[1];
        
        
        return "";
    }
};