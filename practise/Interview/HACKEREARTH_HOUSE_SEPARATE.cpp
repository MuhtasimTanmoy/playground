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

	string s;
	cin >> s;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == '.')
		{
			s[i] = 'B';
		}
	}

	bool possible = true;

	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == s[i + 1] && s[i] == 'H')
		{
			possible = false;
			break;
		}
	}

	cout << (possible ? "YES" : "NO") << endl;
	
	if (possible)
	{
		cout << s << endl;
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
