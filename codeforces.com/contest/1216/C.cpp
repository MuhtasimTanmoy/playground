//https://codeforces.com/contest/1216/problem/C
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
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


bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

pair<pii, pii> intersect(pii a, pii b, pii c, pii d) {
	int lf, rg, up, dn;
	lf = max(min(a.x, b.x), min(c.x, d.x));
	rg = min(max(a.x, b.x), max(c.x, d.x));
	up = min(max(a.y, b.y), max(c.y, d.y));
	dn = max(min(a.y, b.y), min(c.y, d.y));

	if (rg <= lf || up <= dn) return { {0, 0}, {0, 0} };

	return { { lf, dn }, { rg, up } };
}

ll square(pii a, pii b) {
	return 1ll * abs(a.x - b.x) * abs(a.y - b.y);
}


void solve()
{
	vector<pii> p(6);

    REP(i, 6)
		cin >> p[i].x >> p[i].y;

	pair<pii, pii> wb1 = intersect(p[0], p[1], p[2], p[3]);
	pair<pii, pii> wb2 = intersect(p[0], p[1], p[4], p[5]);
	pair<pii, pii> inter = intersect(wb1.x, wb1.y, wb2.x, wb2.y);

	ll swhite = square(p[0], p[1]);
	ll swb1 = square(wb1.x, wb1.y);
	ll swb2 = square(wb2.x, wb2.y);
	ll sinter = square(inter.x, inter.y);

	if (swhite > swb1 + swb2 - sinter) cout << "YES";
	else cout << "NO";	
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
	// cin >> no_of_test_cases;
	no_of_test_cases=1;
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




	
