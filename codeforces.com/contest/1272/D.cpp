//https://codeforces.com/contest/1272//problem/D
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int fr[N], ba[N];
int a[N];



void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i)
		fr[i] = ba[i] = 1;
	for (int i = n - 2; i >= 0; --i)
	{
		if (a[i] < a[i + 1])
			fr[i] = max(fr[i], 1 + fr[i + 1]);
	}
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > a[i - 1])
			ba[i] = max(ba[i], 1 + ba[i - 1]);
	}

	for (int i = 0; i < n; i++)
	{
		cout << fr[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << ba[i] << " ";
	}

	cout << endl;

	int res = *max_element(fr, fr + n);
	for (int i = 1; i + 1 < n; ++i)
	{
		if (a[i - 1] < a[i + 1])
			res = max(res, ba[i - 1] + fr[i + 1]);
	}
	cout << res << "
";
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
