//https://codeforces.com/contest/1234/problem/B
// https://codeforces.com/contest/492/problem/B
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define REPI(i, a, b) for (int i = (a); (i <= (b)); ++i)
#define x first
#define y second
using namespace std;

///REF PII

typedef pair<int, int> pii;

const int INF = 2e9;
const ll INF64 = 1e18;
const int M = 2 * 1000 * 1000;
const int N = 300 * 1000 + 100;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = 3.14159265359;
const int MAX = 1001;

template <typename T>
T gcd(T x, T y)
{
	if (y == 0)
	{
		return x;
	}
	return gcd(y, x % y);
}

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

ll pos[MAX];

void solve()
{
	ll n, l;
	cin >> n >> l;

	REP(i, n)
	{
		cin >> pos[i];
	}

	sort(pos, pos + n);

	REP(i, n)
	{
		cout << pos[i] << " ";
	}

	ll maxx = -1;
	REP(i, n - 1)
	{
		maxx = max(maxx, pos[i + 1] - pos[i]);
	}

	cout << maxx << endl;

	float minDis = maxx / 2.0;

	minDis = max(minDis, (float)(pos[0] - 0));
	minDis = max(minDis, (float)(l - pos[n - 1]));

	printf("%.10f
", minDis);
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
