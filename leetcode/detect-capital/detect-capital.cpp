class Solution {
public:
    void check(char ch, int &countCap, int &countLower)
    {
        if (ch >= 'A' && ch <= 'Z')
            countCap++;

        else if (ch >= 'a' && ch <= 'z')
            countLower++;
    }
 
    bool detectCapitalUse(string word) {
        
        int countCap = 0;
        int countLower = 0;
        
        for ( int i = 0; i < word.length(); i++) {
            check(word[i], countCap, countLower);
        }
      
        if ( countCap == word.length() or countLower == word.length() ){
            return true;
        }
        
        if( word[0] >= 'A' && word[0] <= 'Z' and countLower == word.length() - 1 ){
            return true;
        }
        
        return false;
    }
};