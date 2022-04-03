class Solution {
public:
    string reverseVowels(string s) {
        
        auto isVowel = [&](char& c) -> bool {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' 
                || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        };
        
         auto swap = [](char& a, char& b) {
             a = a ^ b;
             b = a ^ b;
             a = a ^ b;
        };
        
        int start = 0;
        int end = size(s) - 1;
        
        while (true) {
            
            while(!isVowel(s[start])) {
                if (start >= end ) { break; }
                start++;
            }
            
            while(!isVowel(s[end])) {
                if (start >= end ) { break; }
                end--;
            }
            
            if (start >= end ) { break; }

            swap(s[start], s[end]);
            start++;
            end--;
        }
        
        return s;
    }
};


// Alternative

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    string reverseVowels(string s) {
        int beg = 0, end = s.size() - 1;
        string s1 = s;
        
        while (beg < end) {
            if (isVowel(s1[beg]) && isVowel(s1[end])) {
                swap(s1[beg], s1[end]);
                beg++; end--;
            } else if (isVowel(s1[beg])) {
                end--;
            } else if (isVowel(s1[end])) {
                beg++;
            } else {
                beg++;
                end--;
            }
        }
        return s1;
    }
};