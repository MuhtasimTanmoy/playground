//https://1335/problem/D
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
	int holder;

	map<int, int> _map;

	for (int i = 0; i < n; i++)
	{
		cin >> holder;
		_map[holder]++;
	}

	int distinct = 0;
	int most_freq = -1;
	int most_freq_elem = 0;

	for (auto i : _map)
	{
		distinct++;
		if (most_freq < i.second)
		{
			most_freq_elem = i.first;
			most_freq = i.second;
		}
	}
	if (abs(distinct - most_freq)<1)
	{
		distinct--;
	}
	cout << min(distinct, most_freq) << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 0;
	cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}
