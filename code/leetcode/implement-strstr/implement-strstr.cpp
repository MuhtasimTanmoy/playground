class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length(); int h = haystack.length();
        if (needle == "") return 0;
        for(int i = 0; i < h - n  + 1; i++){
            if (haystack.substr(i,n) == needle){
                return i;               
            }
        }
        return -1;
    }
};