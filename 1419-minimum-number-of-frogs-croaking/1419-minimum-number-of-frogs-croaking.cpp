/*
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {        
        int curr = 0;
        unordered_map<char, vector<int>> mapper;
        for (int i = 0; i < croakOfFrogs.size(); i++) {
            auto elem = croakOfFrogs[i];
            mapper[elem].push_back(i);
        }
        
        auto croak = {'r', 'o', 'a', 'k'};
        auto prev = mapper['c'];
        int res = INT_MAX;
        for (auto c: croak) {
            auto now = mapper[c];
            int count = 0;
            for (int i = 0; i < min(prev.size(), now.size()); i++) 
                if (prev[i] < now[i]) 
                    count++;

            res = min(res, count);
            prev = now;
        }
        return res;
    }
};
*/

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> counter(5, 0);
        int frog = 0, maxFrog = 0;
        for (auto c: croakOfFrogs) {
            auto index = string("croak").find(c);
            counter[index]++;
            if (index == 0) maxFrog = max(maxFrog, ++frog);
            else if (--counter[index - 1] < 0) return -1;
            else if (index == 4) frog--;
        }
        return frog == 0 ? maxFrog: -1;
    }
};