#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;


void solve()
{
	int n;
	cin>>n;

	vector< vector<int> > graph(n+1);
	vector< pair<int,int> > ans;

	int from, to;

	for (int i = 0; i < n-1; i++){
		cin>>from>>to;

		graph[from].push_back(to);
		graph[to].push_back(from);

		ans.push_back(make_pair(from,to));
	}

	int res[n];

	int count = 0;
	for (int i = 0; i < n-1; i++){
		if(graph[ans[i].first].size() ==1 || graph[ans[i].second].size()==1){
			res[i] = count++;
		}
	}

	for (int i = 0; i < n-1; i++){
		if(graph[ans[i].first].size() !=1 || graph[ans[i].second].size()!=1){
			res[i] = count++;
		}
	}
	// for(int i=1;i<=n;i++){
	// 	cout<< i << " -> ";
	// 	for(int v : graph[i]){
	// 		cout<<v<<" ";
	// 	}
	// 	cout<<endl;
	// }

	for (int i = 0; i < n-1; i++){
		cout<<res[i]<<" ";
	}


}

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 0;
	// cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();    
	}

	return 0;
}
