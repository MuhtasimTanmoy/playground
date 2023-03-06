class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = size(arr);
        if( n == 1 ) return 0;
        
        unordered_map<int, list<int>> mp;
        for(int i = 0; i < n; i++) mp[arr[i]].push_back(i);
        
        queue<int>q;
        vector<bool>vis(n, false);
        q.push(0); vis[0] = true;
        int step = 0;
        
        while(q.size()) {
            
            int sz = size(q);
            while(sz--) {
                int fr = q.front(); q.pop();
                if (fr == n - 1) return step;
                
                list<int>& neigh=mp[arr[fr]];
                neigh.push_back(fr-1); 
                neigh.push_back(fr+1);
          
                for (auto x: neigh)
                    if (x >= 0 and x < n and !vis[x]) { q.push(x); vis[x] = true; }
                
                neigh.clear();
            }
            step++;
        }
        return 0;
    }
};