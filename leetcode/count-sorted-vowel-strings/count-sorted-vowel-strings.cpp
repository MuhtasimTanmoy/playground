class Solution {
    int result = 0;
    void traverse(int curr, int volwelCount, int n) {
                
        if (n == 0) {
            result++;
            return;
        }
            
        for(int i = curr; i < volwelCount; i++)
            traverse(curr, volwelCount - i, n-1);
    }
    
public:
    int countVowelStrings(int n) {
        traverse(0, 5, n);
        return result;
    }
};