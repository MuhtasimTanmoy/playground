/* Not working
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
*/

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        if (croakOfFrogs.size() % 5 != 0) return -1;
        int frog = 0, maxFrog = 0;
        unordered_map<char, int> mp;
        for (auto &c: croakOfFrogs) {
            mp[c]++;
            switch (c) {
                case 'c': break;
                case 'r': if (mp[c] > mp['c']) return -1; break;
                case 'o': if (mp[c] > mp['r']) return -1; break;
                case 'a': if (mp[c] > mp['o']) return -1; break;
                case 'k':
                    maxFrog = max(maxFrog, mp['c']--);
                    mp['r']--;
                    mp['o']--;
                    mp['a']--;
                    mp['k']--;
                    break;
                default:
                    return -1;
            }
        }
        return (mp['c'] || mp['r'] || mp['o'] || mp['a'] || mp['k']) ? -1: maxFrog;
    }
};