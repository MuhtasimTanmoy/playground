#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

vector<int> res;
class Graph
{
	int vertices;
	vector<int> *edge_list;

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

		res.push_back(i);
	}

public:
	Graph(int no_of_vetices)
	{
		this->vertices = no_of_vetices;
		this->edge_list = new vector<int>[no_of_vetices];
	}

	void addEdge(int from, int to)
	{
		this->edge_list[from].push_back(to);
	}

	vector<pair<int, int>> topsort(bool visited[])
	{
		vector<int> indegree(vertices);

		vector<pair<int, int>> _indegree(vertices);

		for (int i = 0; i < vertices; i++)
		{
			// outdegree.push_back(edge_list[i].size());
			for (auto x : edge_list[i])
			{
				indegree[x] += 1;
			}
		}

		for (int i = 0; i < vertices; i++)
		{
			_indegree[i] = make_pair(indegree[i], i);
		}

		sort(_indegree.begin(), _indegree.end());
		return _indegree;
	}

	vector<int> topsort_variant(bool visited[])
	{
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
	int n;
	cin >> n;

	int edges;
	cin >> edges;

	Graph g(n);

	int from, to;
	for (int i = 0; i < edges; i++)
	{
		cin >> from >> to;
		g.addEdge(from, to);
	}

	bool visited[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}

	// 	for (auto x : g.topsort(visited))
	// {
	// 	cout << x.second << " ";
	// }

	g.topsort_variant(visited);

	// for (auto x : g.topsort_variant(visited))
	// {
	// 	cout << x << " ";
	// }
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
