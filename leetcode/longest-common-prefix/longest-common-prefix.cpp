class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string initial = strs[0];
        if ( strs.size() == 1 ) {
            return initial;
        }
        
        auto presentInOthers = [&] (int currentIndex) -> bool {    
            for (int i = 1; i< strs.size(); i++) {
                if ( initial[currentIndex] != strs[i][currentIndex] ) {
                    return false;
                }
            }
            return true;
        };
        
        int j;
        for (j = 0; j < initial.size(); j++) {
            if ( !presentInOthers(j) ) {
               return initial.substr(0, j);
            } 
        }
        
        if (j == initial.size()) {
            return initial.substr(0, j);
        }
        
        return "";
    }
};