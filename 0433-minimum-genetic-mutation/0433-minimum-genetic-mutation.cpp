class Solution  {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        deque<pair<string,int>> q({{start,0}});
        set<string> b(bank.begin(), bank.end());
        vector<char> nucleotides = {'A', 'T', 'G', 'C'};
        
        while (!q.empty()) {
            auto [g, m] = q.front(); q.pop_front();
            if (g == end) return m;
            
            for (int i = 0; i < g.size(); ++i)
                for (char n : nucleotides) {
                    string gm = g; gm[i] = n;
                    if (b.count(gm)) {
                        b.erase(gm);
                        q.emplace_back(gm, m+1);
                    }
                }
        }
        
        return -1;
    }
};