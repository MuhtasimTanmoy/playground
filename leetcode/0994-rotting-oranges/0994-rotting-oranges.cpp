// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& g) {
//         queue<pair<int, int>> q;
//         for (int i = 0; i < g.size(); i++)
//             for (int j = 0; j < g[i].size(); j++)
//                 if (g[i][j] == 2)
//                     q.push({i, j});
        
//         int res = 0;
//         vector<int> dirs = {0, 1, 0, -1, 0};
        
//         while (q.size()) {
//             cout<<"here s"<<endl;
//             int len = q.size();            
//             while (len--) {
//                 auto [x, y] = q.front(); q.pop();
                
//                 for (int i = 1; i < dirs.size(); i++) {
//                     auto to_x = x + dirs[i - 1], to_y = y + dirs[i];
//                     cout<<"here "<<to_x<<" "<<to_y<<endl;
//                     if (to_x >= 0 && to_y >= 0 
//                         && to_x < g.size() 
//                         && to_y < g[i].size() 
//                         && g[to_x][to_y] == 1) {
//                             cout<<"boo"<<endl;
//                             g[to_x][to_y] = 2;
//                             q.push({to_x, to_y});
//                     }
//                 }
//             }
//             res++;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        
        vector<int> dir={-1, 0 , 1 , 0, -1}; //used for finding all 4 adjacent coordinates
        
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh=0; //To keep track of all fresh oranges left
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        int ans=-1; //initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int r=p.first+dir[i];
                    int c=p.second+dir[i+1];
                    if(r>=0 && r<m && c>=0 && c<n &&grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--; // decrement by 1 foreach fresh orange that now is rotten
                    }
                    
                }
            }
            ans++; //incremented after each minute passes
        }
        if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
        if(ans==-1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
        
    }
};