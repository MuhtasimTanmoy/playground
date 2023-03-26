class Solution {
public:
    int partitionString(string s, int partition_count = 1) {
        vector<int> um(26, 0);
        for (int i = 0; i < s.size(); i++) 
            if (++um[s[i]-'a'] > 1) {
                fill(um.begin(), um.end(), 0);
                um[s[i]-'a'] = 1;
                partition_count++;
            }
        return partition_count;
    }
};