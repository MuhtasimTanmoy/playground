class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, 
                     string ruleValue) {
        
        auto index = [&]() -> int {
            if (ruleKey == "type") return 0;
            if (ruleKey == "color") return 1;
            else return 2;
        };
        int indexToCheck = index();
        
        int res = 0;
        for(auto item: items)
            if (item[indexToCheck] == ruleValue) res++;
        
        return res;
        
    }
};