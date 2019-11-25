#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
ll li[N];

void solve()
{
	ll n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
	}

	ll count = 1;

	for (int i = 1; i < n; i++)
	{
		if (li[i - 1] > li[i])
		{
			count++;
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
	// cin >> no_of_test_cases;
	no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}
