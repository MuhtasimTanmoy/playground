class Solution {
public:
    string predictPartyVictory(string s) {
        int dire = count_if(s.begin(), s.end(), [](auto c) { return c == 'D'; }), 
            radiant = s.size() - dire;
        
        auto ban_dire = 0, ban_radiant = 0;
        while (dire > 0 && radiant > 0) {
            string temp;
            for (auto c: s) {
                if (c == 'R') {
                    if (ban_radiant) { radiant--; ban_radiant--; continue; }
                    ban_dire++;
                } else {
                    if (ban_dire) { dire--; ban_dire--; continue; }
                    ban_radiant++;
                }
                temp.push_back(c);
            }
            swap(temp, s);
        }
        return dire > radiant ? "Dire": "Radiant";
    }
};