class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26, 0);
        for (auto letter: letters) count[letter - 'a']++;
        int n = words.size();
        
        auto can_take = [&](string& now) {
            vector<int> local(26, 0);
            for (auto c:  now) local[c - 'a']++;
            for (auto i = 0; i < local.size(); i++)
                if (local[i] > count[i])
                    return false;
            return true;
        };
        
        auto extract_score = [&score, &count](string& now, int calc = 0) {
            for (auto c: now) 
                calc += score[c - 'a'],
                count[c - 'a']--;
            return calc;
        };
        
        auto reset = [&count](string& now){
            for (auto c: now) count[c - 'a']++;
        };
        
        function<int(int)> go = [&](auto i) {
            if (i == n) return 0;
            auto without = go(i + 1);
            
            auto now = words[i];
            if (can_take(now)) {
                auto scr = extract_score(now);
                without = max(without, scr + go(i + 1));
                reset(now);
            }
            return without;
        };
        
        return go(0);
    }
};