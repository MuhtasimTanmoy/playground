class Solution {
public:
    int minTimeToType(string word) {
        char prev = 'a';
        
        int count = 0;
        for(auto &c: word) {
            if (c == prev) count++;
            else {
                int dist = abs(c - prev);
                cout<<dist<<endl;
                count += min( abs(26 - dist), dist);
                count++;
            }
            prev = c;
        }
        return count;
    }
};