#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

vector<int> factors(int n)
{
	vector<int> f;
	for (int x = 2; x * x <= n; x++)
	{
		while (n % x == 0)
		{
			f.push_back(x);
			n /= x;
		}
	}
	if (n > 1)
		f.push_back(n);
	return f;
}

void solve()
{
	int n;
	cin >> n;

	vector<int> li = factors(n);

	for (auto x : li)
	{
		cout << x << " ";
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 0;
	// cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}
