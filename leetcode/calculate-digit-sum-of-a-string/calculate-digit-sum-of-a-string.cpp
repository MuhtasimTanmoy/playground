class Solution {
public:
    string digitSum(string s, int k) {
        
        if (size(s) <= k) return s;
        
        string processed = "";
        int groupSum = 0;
        for( int i = 0; i < size(s); i++ ) {
            groupSum += (s[i] - '0');
            if ( (i % k) == k -1 || i == size(s) - 1) {
                processed += to_string(groupSum);
                groupSum = 0; 
            }
        }
        return size(processed) > k ? digitSum(processed, k) : processed;
    }
};