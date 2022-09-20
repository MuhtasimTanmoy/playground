//https://codeforces.com/contest/1217/problem/D
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)

using namespace std;
const int N = int(1e6) + 55;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}
// bool visited[128];

int visited[N];

int res[N];
bool cyc = false;
vector<vector<pair<int, int>>> graph(N);

void dfs(int node)
{
	visited[node] = 1;

	for (auto point : graph[node])
	{
		int to = point.first;
		int id = point.second;

		if (visited[to] == 0)
		{
			dfs(to);
			res[id] = 1;
		}
		else if (visited[to] == 2)
		{
			res[id] = 1;
		}
		else
		{
			cyc = true;
			res[id] = 2;
		}
	}
	visited[node] = 2;
}	

void solve()
{
	int n, m;
	cin >> n >> m;

	int from, to;

	//normal

	REP(i, m)
	{
		cin >> from >> to;
		from--;
		to--;
		graph[from].push_back(make_pair(to, i));
	}

	for (int i = 0; i <n; i++)
	{
		if (!visited[i])
			dfs(i);
	}

	cout << (cyc ? 2 : 1);

	cout<<endl;

	REP(i, m)
	{ 
		cout << res[i] << " ";
	}

	cout << endl;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	ios_base::sync_with_stdio(false);
	int no_of_test_cases;
	//cin >> no_of_test_cases;
	no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	return 0;
}

// TAG BFS / DFS
