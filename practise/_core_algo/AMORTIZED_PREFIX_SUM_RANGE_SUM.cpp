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

	int start, end;

	cin >> start >> end;

	int li[n];

	int cumulative[n];

	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
	}

	//////////////  Sum Query

	cumulative[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		cumulative[i] = cumulative[i - 1] + li[i - 1];
	}

	for (int i = 0; i < n; i++)
	{
		cout << cumulative[i] << " ";
	}

	cout << endl;

	cout << cumulative[end] - cumulative[start - 1] << endl;
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
