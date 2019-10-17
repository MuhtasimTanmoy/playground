//https://codeforces.com/contest/1238/problem/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;
int li[N];

void solve()
{
	ll n, r;
	cin >> n >> r;

	ll unique = 0;
	ll holder;

	ll left_limit = 0;
	bool check_set[N] = {false};

	for (int i = 0; i < n; i++)
	{
		cin >> holder;
		if (!check_set[holder])
		{
			li[unique] = holder;
			check_set[holder] = true;
			unique++;
		}
	}

	ll count = 0;

	sort(li, li + unique);

	if (unique == 1)
	{
		cout << 1 << endl;
		return;
	}
	else if (unique == 2)
	{
		cout << ((li[unique - 2] - r <= left_limit) ? 1 : 2) << endl;
		return;
	}

	int right_left = unique;

	while (left_limit + r < li[right_left - 2])
	{
		left_limit += r;
		right_left--;
		count++;
	}

	count++;
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
