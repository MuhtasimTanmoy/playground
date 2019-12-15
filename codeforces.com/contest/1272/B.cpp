//https://codeforces.com/contest/1272//problem/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const ll N = 2e5 + 11;

void solve()
{
	ll total, got;
	cin >> total >> got;

	string s;
	cin >> s;
	s += "$";

	unordered_set<ll> _set;

	char holder;

	ll calc[s.size()];

	for (ll i = 0; i < got; i++)
	{
		cin >> holder;
		_set.insert(holder);
	}

	ll count = 1;
	vector<ll> check;

	for (ll i = 0; i < s.size(); i++)
	{
		if (_set.count(s[i]))
		{
			calc[i] = count;
			count++;
		}
		else
		{
			calc[i] = 0;
			count = 1;
			check.push_back(i);
		}
	}

	ll res = 0;
	ll calculate = 0;

	for (auto x : check)
	{
		if (x - 1 >= 0)
		{
			calculate = calc[x - 1];
			res += (calculate * (calculate + 1)) >> 1;
		}
	}

	cout << res << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll no_of_test_cases = 0;
	// cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}
