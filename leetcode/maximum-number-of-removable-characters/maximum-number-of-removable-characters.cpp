class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
 
        function<bool(string)> isSubsequence = [&] (string fullText) -> bool {
            int match = 0;
            for(int i = 0; i< fullText.size(); i++) {
                if (fullText[i] == p[match] ) {
                    match++;
                }
            }
            return match == p.size();
        };
        
        
        function<bool(int)> check = [=](int mid) -> bool {
            cout<<mid<<endl;
            string processedStr = s;
            for(int i=0; i< mid; i++) {
                processedStr[removable[i]] = '.';
            }
            return isSubsequence(processedStr);
        };
        
        function<int()> binarySearchPortion = [&]() -> int {
            int left = 0;
            int right = removable.size();
            int mid;
            
            while(left <= right)  {
                mid = (left + right) >> 1;
                
                if (check(mid)) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return right;
        };
        
        return binarySearchPortion();
    }
};