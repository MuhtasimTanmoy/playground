#include "bits/stdc++.h"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(V) (V).begin(), (V).end()
using namespace std;
typedef long long ll;
#define V 9


// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool sptSet[]) 
{ 
   // Initialize min value 
   int min = INT_MAX, min_index; 
   
   for (int v = 0; v < V; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index; 
} 

void dijkstra(int graph[9][9], int src) 
{ 
     int dist[V];     // The output array.  dist[i] will hold the shortest 
                      // distance from src to i 
   
     bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
                     // path tree or shortest distance from src to i is finalized 
   
     // Initialize all distances as INFINITE and stpSet[] as false 
     for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
   
     // Distance of source vertex from itself is always 0 
     dist[src] = 0; 
   
     // Find shortest path for all vertices 
     for (int count = 0; count < V-1; count++) 
     { 
       // Pick the minimum distance vertex from the set of vertices not 
       // yet processed. u is always equal to src in the first iteration. 
       int u = minDistance(dist, sptSet); 
   
       // Mark the picked vertex as processed 
       sptSet[u] = true; 
   
       // Update dist value of the adjacent vertices of the picked vertex. 
       for (int v = 0; v < V; v++) 
   
         // Update dist[v] only if is not in sptSet, there is an edge from  
         // u to v, and total weight of path from src to  v through u is  
         // smaller than current value of dist[v] 
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX  
                                       && dist[u]+graph[u][v] < dist[v]) 
            dist[v] = dist[u] + graph[u][v]; 
     } 
   
     // print the constructed distance array 
     printSolution(dist, V); 
} 
 
int main() {fio;
	freopen("input.txt", "r", stdin);

	int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 

	int n;
	cin >> n;
	vector <vector <int> > D(n, vector <int> (n, 1e9));
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < n; j++) {
			if(s[j] == '1') {
				D[i][j] = 1;
			}
		}
		D[i][i] = 0;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				D[j][k] = min(D[j][k], D[j][i] + D[i][k]);
			}
		}
	}
	int m;
	cin >> m;
	vector <int> p(m);
	for(int &u : p) {
		cin >> u;
		u--;
	}
	vector <int> ans = {p[0], p[1]};
	for(int i = 2; i < m; i++) {
		int y = ans.size() - 1;
		while(y > 0 && D[ans[y - 1]][ans[y]] + D[ans[y]][p[i]] == D[ans[y - 1]][p[i]]) {
			ans.pop_back();
			y--;
		}
		cout<<p[i]<<endl;
		ans.push_back(p[i]);
	}
	cout << ans.size() << endl;
	for(int u : ans) {
		cout << u + 1 << ' ';
	}
 
    return 0;
}