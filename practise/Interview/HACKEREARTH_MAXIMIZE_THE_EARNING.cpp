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
	ll n, rupee;
	cin >> n >> rupee;

	ll holder;
	ll max_so_far = INT64_MIN;

	ll count = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> holder;
		if (holder > max_so_far)
			count++;
		max_so_far = max(max_so_far, holder);
	}

	cout << rupee * count << endl;
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
