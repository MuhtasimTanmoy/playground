#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

class Graph
{
	int vertices;
	bool isUndirecetd;
	vector<int> * edge_list;

	void DFS(int i, bool visited[])
	{
		visited[i] = true;

		cout << i << " ";

		for (auto x : edge_list[i])
		{
			if (!visited[x])
			{
				DFS(x, visited);
			}
		}
	}

public:
	Graph(int no_of_vetices, bool isUndirected)
	{
		this->vertices = no_of_vetices;
		this->isUndirecetd = isUndirecetd;
		this->edge_list = new vector<int> [no_of_vetices];
	}

	void addEdge(int from, int to)
	{
		edge_list[from].push_back(to);
		if (isUndirecetd)
		{
			edge_list[to].push_back(from);
		}
	}

	void start_dfs(int start, bool visited[])
	{
		DFS(start, visited);

		for (int i = 0; i < vertices; i++)
		{
			if (!visited[i])
			{
				DFS(i, visited);
			}
		}
	}
};

void solve()
{
	int n, edge;
	cin >> n >> edge;

	int from, to;

	Graph *graph = new Graph(n, true);

	for (int i = 0; i < edge; i++)
	{
		cin >> from >> to;
		graph->addEdge(from, to);
	}

	bool visited[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}

	graph->start_dfs(0, visited);
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
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
