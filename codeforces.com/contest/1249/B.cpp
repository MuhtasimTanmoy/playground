//https://codeforces.com/contest/1249//problem/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int li[N];

void solve()
{
	int n;
	cin >> n;

	int dest = 0;

	vector<int> res;

	for (int i = 1; i <= n; i++)
	{
		cin >> li[i];
	}

	int count = 1;
	for (int i = 1; i <= n; i++)
	{
		dest = li[i];
		while (i != dest)
		{
			count++;
			dest = li[dest];
		}
		res.push_back(count);
		count = 1;
	}

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
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
