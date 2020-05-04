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
	int point[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> point[i];
	}
	string s;
	cin >> s;

	ll sum = 0;

	for (int i = 0; i < s.size(); i++)
	{
		sum += point[s[i] - '1'];
	}

	cout << sum << endl;
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
