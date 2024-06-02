class Solution {
public:
    vector<string> findAllRecipes(vector<string>& make, 
                                  vector<vector<string>>& need, 
                                  vector<string>& have) {
        unordered_set<string> bag, curr_have (have.begin(), have.end());
        bool could_add = true;
        while (could_add) {
            could_add = false;
            for (auto i = 0; i < make.size(); i++) {
                if (bag.count(make[i])) continue;
                
                bool has_missing = false;
                for (auto j = 0; j < need[i].size(); j++) 
                    if (!curr_have.count(need[i][j])) {
                        has_missing = true;
                        break;
                    }
                
                if (!has_missing) 
                    bag.insert(make[i]),
                    curr_have.insert(make[i]),
                    could_add = true;
            }
        }
        return vector<string>(bag.begin(), bag.end());
    }
};