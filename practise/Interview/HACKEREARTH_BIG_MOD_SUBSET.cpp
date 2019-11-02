#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e9 + 7;

void solve()
{
	ull n;
	cin >> n;

	ull subset = pow(2, n - 1);

	ull holder = 0;
	ull count = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> holder;
		if (holder >= subset)
		{
			count += holder;
			count = count % N;
		}
	}

	cout << count << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases;
	cin >> no_of_test_cases;
	// no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}
