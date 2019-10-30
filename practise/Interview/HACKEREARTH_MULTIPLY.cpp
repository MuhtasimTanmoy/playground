#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;

	vector<int> li(n);
	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
	}

	ll res = 1;

	for (int i = 0; i < n; i++)
	{
		res = (res * li[i]) % N;
	}

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
