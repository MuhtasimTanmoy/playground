class Solution {
public:
  string convert(string s, int numRows) {
        
        vector<vector<int>> list(numRows);
        
        vector<int> index;
        int currentIndex = 0;
        
        // Update index
        auto updateIndex = [&]() {
            for( int i = 0; i < numRows; i++) {
                index.push_back(i);
            }

            for( int i = numRows - 2; i > 0; i--) {
                index.push_back(i);
            }
        };
        updateIndex();
        
        auto getIndex = [&](int i) -> int {
			int returnIndex = i % index.size();
            return index[returnIndex];
        };
       
        for( int i = 0; i< s.size(); i++) {
            char current = s[i];
            list[getIndex(i)].push_back(current);
        }
        
        string st = "";
        for( int i = 0; i < numRows; i++) {
            for (char a: list[i]) {
                st+=a;
            }
        }
        return st;
    }
};