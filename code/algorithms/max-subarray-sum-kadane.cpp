#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void solve()
{
	int n;
	cin >> n;
	int li[n];

	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
	}

	int max_sum = 0;
	int cached = 0;

	for (int i = 0; i < n; i++)
	{
		max_sum += li[i];
		max_sum = max(max_sum, 0);
		cached = max(max_sum, cached);
	}

	cout << cached << endl;
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
