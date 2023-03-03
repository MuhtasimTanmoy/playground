class Solution {
public:
    int strStr(string haystack, string needle) {
        auto index = haystack.find(needle);
        return index == string::npos ? -1 : index;
    }
};