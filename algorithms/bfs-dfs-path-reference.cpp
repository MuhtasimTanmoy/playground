#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
int n;
int r[] = {1, 0, 0, -1};
int c[] = {0, 1, -1, 0};

char mat[100][100];
bool visited[100][100];

typedef struct point {
	int x;
	int y;
} point;

point cur;
point parent[100][100];
point res;

point dfs(point p) {
	cur.x = p.x;
	cur.y = p.y;

	if (p.x < 0 || p.x > n - 1 || p.y < 0 || p.y > n - 1) {
	} else {
		visited[p.x][p.y] = true;

		if (mat[p.x][p.y] == 'e') {
			cout << endl
				 << p.x << "...." << p.y << "...." << endl;
			cout << "Found" << endl;
			res = p;
		}

		for (int i = 0; i < 4; i++) {
			cur.x = p.x + r[i];
			cur.y = p.y + c[i];

			if (!visited[cur.x][cur.y]) {
				parent[cur.x][cur.y] = p;
				dfs(cur);
			}
		}
	}
}

void bfs(int x, int y) {
	queue<point> q;
	point p;
	p.x = x;
	p.y = y;
	q.push(p);
	visited[x][y] = true;

	while (!q.empty()) {
		point get = q.front();
		q.pop();
		visited[get.x][get.y] = true;

		if (mat[get.x][get.y] == 'e') {
			cout << "Found" << endl;
			res.x = get.x;
			res.y = get.y;
			return;
		}

		point _try;

		for (int i = 0; i < 4; i++) {
			_try.x = get.x + r[i];
			_try.y = get.y + c[i];
			if (_try.x < 0 || _try.x > n - 1 || _try.y < 0 || _try.y > n - 1) {
				continue;
			}
			if (!visited[_try.x][_try.y]) {
				parent[_try.x][_try.y] = get;
				q.push(_try);
			}
		}
	}
}

void solve()
{
	cin >> n;
	char holder;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> holder;
			mat[i][j] = holder;
		}
	}
	point x;
	x.x = 0;
	x.y = 0;
	// dfs(x);

	// while (res.x != 0 || res.y != 0)
	// {
	// 	res = parent[res.x][res.y];
	// 	cout << res.x << " " << res.y << endl;
	// }

	bfs(x.x, x.y);
	cout << res.x << " " << res.y << endl;

	while (res.x != 0 || res.y != 0)
	{
		res = parent[res.x][res.y];
		cout << res.x << " " << res.y << endl;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 1;
	// cin >> no_of_test_cases;
	while (no_of_test_cases--)solve();
	return 0;
}
