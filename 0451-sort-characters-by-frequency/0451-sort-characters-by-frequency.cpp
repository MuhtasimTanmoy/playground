class Solution {
public:
    string frequencySort(string s) {
        vector<int> li(128, 0);
        for (auto c: s) li[c]++;
        
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < 128; i++)  
            if (li[i]) 
                pq.push(make_pair(li[i], i));
        
        string ans = "";
        while (pq.size()) {
            auto c = pq.top();
            pq.pop();
            while (c.first--) ans += c.second;
        }
        return ans;
    }
};