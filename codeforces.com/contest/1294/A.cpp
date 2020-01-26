//https://codeforces.com/contest/1294/problem/A
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

	int a[3];
	cin >> a[0] >> a[1] >> a[2];

	int n;
	cin >> n;

	ll sum = a[0] + a[1] + a[2] + n;

	sort(a, a + 3);

	int need_to_conform = a[2] - a[1] - a[0];
	int also_need_to_conform = a[1] - a[0];

	if (sum % 3 == 0 && need_to_conform <= n && (also_need_to_conform <= (n - a[2]+a[1])))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
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
