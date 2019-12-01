//https://codeforces.com/contest/1041//problem/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void solve()
{
	ll a, b, x, y;
	cin >> a >> b >> x >> y;

	ll divide_both = gcd(x, y);
	x /= divide_both;
	y /= divide_both;

	ll res = min(a / x, b / y);
	cout << res << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases;
	// cin >> no_of_test_cases;
	no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}
