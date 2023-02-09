/*
TLE
class Solution {
public:
    long long distinctNames(vector<string>& ideas, int res = 0) {
        unordered_set<string> bag(ideas.begin(), ideas.end());
        for (int i = 0; i < ideas.size(); i++)
            for (int j = i + 1; j < ideas.size(); j++) {
                auto& left = ideas[i], right = ideas[j];
                swap(left[0], right[0]);
                
                if (!bag.count(left) && !bag.count(right)) res += 2;
                swap(left[0], right[0]);
            }
        return res;    
    }
};
*/

class Solution {
public:
    long long distinctNames(vector<string>& ideas, long long res = 0) {
        unordered_set<string> grp[26];
        for (auto idea: ideas) 
            grp[idea[0] - 'a'].insert(idea.substr(1));
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++) {
                long long l = 0, r = 0;
                for (auto el: grp[i]) if (!grp[j].count(el)) l++;
                for (auto el: grp[j]) if (!grp[i].count(el)) r++;
                res += l * r;
            }
        return res;
    }
};