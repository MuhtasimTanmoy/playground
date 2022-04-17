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

	int away_kit[100+1];

	for (int i = 0; i <= 100; i++)
	{
		away_kit[i] = 0;
	}
	int home, away;

	int home_kit[n];

	for (int i = 0; i < n; i++)
	{
		cin >> home >> away;
		home_kit[i] = home;
		away_kit[away]++;
	}

	int required_away_kit_for_host = 0;

	for (int i = 0; i < n; i++)
	{
		required_away_kit_for_host += (away_kit[home_kit[i]]);
	}

	cout << required_away_kit_for_host << endl;
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
