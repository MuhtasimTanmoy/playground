class Solution {
public:
    int minDistance(string word1, string word2) {
        
        // longest common subsequence
                
//         int word1Len = word1.size();
//         int word2Len = word2.size();
        
//         vector<vector<int>> dp(word1Len + 1,
//                                vector<int>(word2Len + 1, 0)
//                               );
        
//         for (int i = 1; i<= word1Len; i++) {
            
//             for (int j = 1; j<= word2Len; j++) {
                
//                 if ( word1[i - 1] == word2[ j - 1] ) {
                    
//                     dp[i][j] = dp[i-1][j-1] + 1;
                    
//                 } else {
                    
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    
//                 }
                
//             }
//         }
        
//         int lcs = dp[word1Len][word2Len];
//         return word1Len + word2Len - 2 * lcs;
        
        int word1Len = size(word1);
        int word2Len = size(word2);
        
        vector<int> current(word2Len + 1, 0);
        vector<int> previous(word2Len + 1, 0);
        
        for (int i = 1; i <= word1Len; i++) {
            
            for (int j = 1; j <= word2Len; j++) {
                                    
                current[j] = word1[i-1] == word2[j-1] 
                    ? 
                    previous[j-1]+ 1 
                    : max(current[j-1], previous[j]);
            }
            previous = current;
        }
        
        int lcs = current[word2Len];
        return word1Len + word2Len - 2 * lcs;
    }
};