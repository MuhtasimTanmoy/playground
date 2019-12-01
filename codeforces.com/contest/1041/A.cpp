//https://codeforces.com/contest/1041//problem/A
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1001;

void solve()
{
	int n;
	cin >> n;
	int li[n];

	int _min = INT32_MAX;
	int _max = INT32_MIN;

	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
		_min = min(_min, li[i]);
		_max = max(_max, li[i]);
	}

	cout << (_max - _min + 1) - n << endl;
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
