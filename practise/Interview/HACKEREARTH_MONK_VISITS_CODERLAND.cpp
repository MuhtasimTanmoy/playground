#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const ull N = 1e18;

void solve()
{
	ll checkpoints;
	cin >> checkpoints;

	ll price[checkpoints];
	ll petrol_needed[checkpoints];

	ll min_so_far = INT32_MAX;

	for (ll i = 0; i < checkpoints; i++)
	{
		cin >> price[i];
		min_so_far = min(min_so_far, price[i]);
		price[i] = min_so_far;
	}

	for (ll i = 0; i < checkpoints; i++)
	{
		cin >> petrol_needed[i];
	}

	ll total_cost = 0;
	for (ll i = 0; i < checkpoints; i++)
	{
		total_cost += price[i] * petrol_needed[i];
	}

	cout << total_cost << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll no_of_test_cases;
	cin >> no_of_test_cases;
	// no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}
