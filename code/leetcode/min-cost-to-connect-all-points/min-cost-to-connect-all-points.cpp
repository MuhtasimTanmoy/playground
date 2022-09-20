class Solution {
public:
    int par[1001]; 
    // parent array to store parent of every node
    // Kruskal uses DSU
    
    int find(int a) // find function to find parent of a node
    {
        if(par[a] < 0)
            return a;
        
        return par[a] = find(par[a]); // path compression
    }
    
    // Union function to make one node parent of anthor
    void Union(int a, int b)
    {
        par[a] = b; // here we are making parent of a to b
    }
    
    int minCostConnectPoints(vector<vector<int>>& arr) {
        int n = arr.size(); // extract the size of array
        
        // Intially all are alone, so everyone is -1
        for(int i = 0; i < n; i++) par[i] = -1;
        
        // define adj vector to store three things
        // first value store weight where
        // weight is actually manhattan distance
        
        vector<pair<int, pair<int, int>>> adj;
        
        // generating graph basically with weights
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int weight = abs(arr[i][0] - arr[j][0]) + 
                             abs(arr[i][1] - arr[j][1]);//manhattan distance
                
                adj.push_back({weight, {i, j}});
                
            }
        }
        
        // sort on the basis of their edge weight
        sort(adj.begin(), adj.end());
        
        int sum = 0; //intially define sum as zero
        
        // for each edge we travel
        for(int i = 0; i < adj.size(); i++)
        {
            int a = find(adj[i].second.first); // first node
            int b = find(adj[i].second.second); // second node
            
            if(a != b) // if both parents are not same then add weight
            {
                sum += adj[i].first;
                Union(a, b); // now merge them
            }
        }
        
        return sum; // finally return sum
    }
};