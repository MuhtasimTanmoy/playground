class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int remaining = false;
        bool plusOne = true;
        
        int current = digits.size() - 1;
        while (current >= 0 && (remaining || plusOne)) {
            
            if (plusOne || remaining) {
                
               digits[current] += 1;
                
               if( digits[current] == 10) {
                    remaining = true;
                    digits[current] = 0;
               } else{
                   remaining = false;
               }
               plusOne = false;
            }
            current--;
        }
        
        if (remaining) {
            vector<int> result;
            result.push_back(1);
            
            for(int i: digits) {
                result.push_back(i);
            }
            return result;
        }
        
        return digits;
    }
};