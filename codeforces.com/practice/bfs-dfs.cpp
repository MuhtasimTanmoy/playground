#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)

using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}
// bool visited[128];

bitset<128> visited(0);
vector<vector<int>> graph(128);

vector<vector<pair<int,int>>> graph(128);


void dfs(int node)
{
	visited[node] = 1;
	cout << node << endl;

	for (int i = 0; i < graph[node].size(); i++)
	{
		if (!visited[graph[node][i]])
		{
			dfs(graph[node][i]);
		}
		else
		{
			cout << graph[node][i] << " Seen before" << endl;
		}
	}
}


queue<int> q;

void bfs(int n)
{

	q.push(n);
	visited[n] = 1;

	while (!q.empty())
	{
		int node = q.front();
		cout << node << endl;
		q.pop();

		for (int child : graph[node])
		{
			if (!visited[child])
			{
				q.push(child);
				visited[child] = 1;
			}
		}
	}
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
		graph[from].push_back(to);
	}

	for (int i = n; i >= 1; i--)
	{
		if (!visited[i])
			dfs(i);
	}

	cout << endl;

	visited.reset();

	// for (int i = n; i >0; i--)
	// {
	// 	if (!visited[i])
	// 	{
	// 		bfs(i);
	// 	}
	// }
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