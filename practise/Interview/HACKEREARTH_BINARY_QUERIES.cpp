#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void solve()
{
	int n;
	cin >> n;

	int holder;

	unordered_map<int, int> _map;

	for (int i = 0; i < n; i++)
	{
		cin >> holder;
		if (_map.count(holder) == 0)
		{
			_map[holder] = 1;
		}
		else
		{
			_map[holder]++;
		}
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; i++)

	{
		cin >> holder;
		if (_map.count(holder))
		{
			cout << _map[holder] << endl;
		}
		else
		{
			cout << "NOT PRESENT" << endl;
		}
	}
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
