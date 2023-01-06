class Solution {
public:
    int countSegments(string s) {        
        stringstream ss(s); string word;
        int count = 0;
        while (ss >> word) count++;
        return count;
    }
};