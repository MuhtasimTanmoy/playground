class Solution {
public:
    string reverseWords(string s) {
        
        auto reverse = [&](int left, int right) {
            while(left < right) {
                auto c = s[left];
                s[left] = s[right];
                s[right] = c;
                left++;
                right--;
            }
        };
        
        
        int tokenBegin = 0;
        int tokenEnd = 0;
        
        while(tokenBegin < size(s)) {
            while(tokenEnd < size(s) && s[tokenEnd] != ' ') tokenEnd++;
            reverse(tokenBegin, tokenEnd - 1);
            tokenEnd++;
            tokenBegin = tokenEnd;
        }
        
        return s;
    }
};

// Previous

// class Solution {
    
//     typedef struct Span {
//         int start;
//         int end;
        
//         Span(int start, int end)
//         : start(start)
//         ,end(end)
//         {}
        
//     } Span; 
    
// public:
//     string reverseWords(string s) {
        
//         vector<Span> spaceOccurence;
//         int traverse = 0;
        
//         int start = 0;
//         int end = size(s) - 1;
        
//         for(int i = 0; i <= size(s); i++) {
//             if(s[i] == ' ' || i ==  size(s)) {
//                 spaceOccurence.emplace_back(start, i-1);
//                 start = i + 1;
//                 traverse++;
//             }
//         }
        
//         auto swap = [](char& a, char& b) {
//             a = a ^ b;
//             b = a ^ b;
//             a = a ^ b;
//         };
        
//         auto reverse = [&](int start, int end) {
//             while(start < end) {
//                 swap(s[start], s[end]);
//                 start++;
//                 end--;
//             }
//         };
        
//         for(int word = 0; word < size(spaceOccurence); word++) {
//             reverse(spaceOccurence[word].start, spaceOccurence[word].end);
//         }
        
//         return s;
        
//     }
// };