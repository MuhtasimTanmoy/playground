#include "bits/stdc++.h"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(V) (V).begin(), (V).end()
using namespace std;
typedef long long ll;
 
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
		for(int j = 0; j < n; j++) 
			if(s[j] == '1') 
				D[i][j] = 1;

		D[i][i] = 0;
	}

	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++) 
			for(int k = 0; k < n; k++) 
				D[j][k] = min(D[j][k], D[j][i] + D[i][k]);

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
	for(int u : ans) 
		cout << u + 1 << ' ';
		 
    return 0;
}